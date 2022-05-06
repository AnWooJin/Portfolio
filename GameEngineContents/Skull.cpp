#include "HellTakerGame.h"
#include "Skull.h"
#include "MoveEffect.h"
#include "HitEffect.h"
#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineImageManager.h>

Skull::Skull()
	: MyRenderer_(nullptr)
	, MyPlayer_(nullptr)
	, ColMapImage_(nullptr)
	, CurState_(SkullState::Max)
	, MyCollision_(nullptr)
	, Time_(0.0f)
{
}

Skull::~Skull()
{
}

void Skull::Start()
{
	MyRenderer_ = CreateRenderer();
	MyRenderer_->CreateAnimation("Skull_Idle.bmp", "Skull_Idle", 0, 11, 0.065f);
	MyRenderer_->CreateAnimation("Skull_Hit.bmp", "Skull_Hit", 0, 7, 0.03f, false);
	MyRenderer_->ChangeAnimation("Skull_Idle");
	MyCollision_ = CreateCollision("Skull", { 30,30});
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


void Skull::SetColImage(int _Chapter)
{
	switch (_Chapter)
	{
	case 1:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter1_ColMap.bmp");
		break;
	case 2:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter2_ColMap.bmp");
		break;
	case 3:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter3_ColMap.bmp");
		break;
	case 4:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter4_ColMap.bmp");
		break;
	case 5:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter5_ColMap.bmp");
		break;
	case 6:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter6_ColMap.bmp");
		break;
	case 7:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter7_ColMap.bmp");
		break;
	case 8:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter8_ColMap.bmp");
		break;
	case 9:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter9_ColMap.bmp");
		break;
	default:
		break;
	}
}

void Skull::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	int Chapter = dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount();
	SetColImage(Chapter);
	ChangeState(SkullState::Idle);
}