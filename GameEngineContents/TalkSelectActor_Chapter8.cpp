#include "TalkSelectActor_Chapter8.h"
#include <GameEngine/GameEngineRenderer.h>

TalkSelectActor_Chapter8::TalkSelectActor_Chapter8()
	:MyRenderer0_(nullptr),
	MyRenderer1_(nullptr),
	ChangeTime_(2.5f),
	IsSelect0_(false),
	IsSelect1_(false),
	Selected0_(true),
	SelectActorSetNum_(0),
	CurState_(TalkSelectActor_Chapter8State::Max)
{
}

TalkSelectActor_Chapter8::~TalkSelectActor_Chapter8()
{
}


void TalkSelectActor_Chapter8::Start()
{
	LevelRegist("TalkSelectActor_Chapter8");
	MyRenderer0_ = CreateRenderer();
	MyRenderer1_ = CreateRenderer();
	MyRenderer0_->Off();
	MyRenderer1_->Off();
	MyRenderer0_->CreateAnimation("Booper.bmp", "Booper", 0, 18, 0.1f);
	MyRenderer0_->CreateAnimation("Success.bmp", "Success", 0, 8, 0.1f,false);
	ChangeState(TalkSelectActor_Chapter8State::Empty);
	
}

void TalkSelectActor_Chapter8::Update()
{
	StateUpdate();
}


void TalkSelectActor_Chapter8::ChangeState(TalkSelectActor_Chapter8State _State)
{
	if (CurState_ == _State)
	{
		return;
	}
	switch (_State)
	{
	case TalkSelectActor_Chapter8State::Empty:
		EmptyStart();
		break;
	case TalkSelectActor_Chapter8State::Booper:
		BooperStart();
		break;
	case TalkSelectActor_Chapter8State::SelectActor:
		SelectActorStart();
		break;
	case TalkSelectActor_Chapter8State::Success:
		SuccessStart();
		break;
	case TalkSelectActor_Chapter8State::Max:
		break;
	default:
		break;
	}

	CurState_ = _State;
}

void TalkSelectActor_Chapter8::StateUpdate()
{
	switch (CurState_)
	{
	case TalkSelectActor_Chapter8State::Empty:
		EmptyUpdate();
		break;
	case TalkSelectActor_Chapter8State::Booper:
		BooperUpdate();
		break;
	case TalkSelectActor_Chapter8State::SelectActor:
		SelectActorUpdate();
		break;
	case TalkSelectActor_Chapter8State::Success:
		SuccessUpdate();
		break;
	case TalkSelectActor_Chapter8State::Max:
		break;
	default:
		break;
	}
}


void TalkSelectActor_Chapter8::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	ChangeState(TalkSelectActor_Chapter8State::Empty);
	ChangeTime_ = 2.5f;
	MyRenderer0_->Off();
	MyRenderer1_->Off();
	IsSelect0_ = false;
	IsSelect1_ = false;
	Selected0_ = true;
	SelectActorSetNum_ = 0;
}
