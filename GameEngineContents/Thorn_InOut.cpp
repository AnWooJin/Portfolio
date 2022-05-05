#include "Thorn_InOut.h"
#include "Player.h"
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineCollision.h>

Thorn_InOut::Thorn_InOut()
	: MyRenderer_(nullptr)
	, MyCollision_(nullptr)
	, MyPlayer_(nullptr)
	, MoveCount_(0)
{
}

Thorn_InOut::~Thorn_InOut()
{
}

void Thorn_InOut::Start()
{
	if (nullptr == MyRenderer_)
	{
		MyRenderer_ = CreateRenderer("Empty.bmp");
		MyRenderer_->CreateAnimation("Thorn_InAni.bmp", "Thorn_In", 0, 5, 0.05f,false);
		MyRenderer_->CreateAnimation("Thorn_OutAni.bmp", "Thorn_Out", 0, 5, 0.05f, false);
		MyCollision_ = CreateCollision("Thorn", { 20,20 });
	}
	MyPlayer_ = GetLevel()->FindActor<Player>("Player");
	ChangeState(Thorn_InOutState::Max);
}

void Thorn_InOut::Update()
{
	StateUpdate();
}

void Thorn_InOut::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	MoveCount_ = MyPlayer_->GetMoveCount();
}


void Thorn_InOut::SetState(Thorn_InOutState _State)
{
	switch (_State)
	{
	case Thorn_InOutState::In:
		MyRenderer_->SetImageAnimationReset("Thorn_In.bmp");
		MyCollision_->Off();
		break;
	case Thorn_InOutState::Out:
		MyRenderer_->SetImageAnimationReset("Thorn_Out.bmp");
		MyCollision_->On();
		break;
	case Thorn_InOutState::Max:
		break;
	default:
		break;
	}
	CurState_ = _State;
}

void Thorn_InOut::ChangeState(Thorn_InOutState _State)
{
	if (CurState_ == _State)
	{
		return;
	}
	
	switch (_State)
	{
	case Thorn_InOutState::In:
		InStart();
		break;
	case Thorn_InOutState::Out:
		OutStart();
		break;
	case Thorn_InOutState::Max:
		break;
	default:
		break;
	}

	CurState_ = _State;
}

void Thorn_InOut::StateUpdate()
{
	switch (CurState_)
	{
	case Thorn_InOutState::In:
		InUpdate();
		break;
	case Thorn_InOutState::Out:
		OutUpdate();
		break;
	case Thorn_InOutState::Max:
		break;
	default:
		break;
	}
}