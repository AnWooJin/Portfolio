#include "HellTakerGame.h"
#include "Skull.h"
#include "MoveEffect.h"
#include "HitEffect.h"
#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineCollision.h>

Skull::Skull()
	: MyRenderer_(nullptr)
	, MyPlayer_(nullptr)
	, CurState_(SkullState::Max)
	, MyCollision_(nullptr)
{
}

Skull::~Skull()
{
}

void Skull::Start()
{
	MyRenderer_ = CreateRenderer();
	MyRenderer_->CreateAnimation("Skull_Idle.bmp", "Skull_Idle", 0, 11, 0.065f);
	MyRenderer_->CreateAnimation("Skull_Hit.bmp", "Skull_Hit", 0, 7, 0.05f, false);
	MyRenderer_->ChangeAnimation("Skull_Idle");
	MyCollision_ = CreateCollision("Skull", { 60,60});
	MyPlayer_ = GetLevel()->FindActor<Player>("Player");
	ChangeState(SkullState::Idle);
}

void Skull::Update()
{
	if (8 == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount())
	{
		MyRenderer_->CameraEffectOn();
	}
	else
	{
		MyRenderer_->CameraEffectOff();
	}

	StateUpdate();
}


void Skull::ChangeState(SkullState _State)
{
	if (CurState_ == _State)
	{
		return;
	}
	CurState_ = _State;

	switch (CurState_)
	{
	case SkullState::Idle:
		IdleStart();
		break;
	case SkullState::Hit:
		HitStart();
		break;
	case SkullState::Max:
		break;
	default:
		break;
	}
}

void Skull::StateUpdate()
{
	switch (CurState_)
	{
	case SkullState::Idle:
		IdleUpdate();
		break;
	case SkullState::Hit:
		HitUpdate();
		break;
	case SkullState::Max:
		break;
	default:
		break;
	}
}
