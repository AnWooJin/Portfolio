#include "HellTakerGame.h"
#include "TalkSelectActor.h"
#include "TalkLevel.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineSound.h>

TalkSelectActor::TalkSelectActor()
	: MyRenderer0_(nullptr),
 	  MyRenderer1_(nullptr),
	  IsSelect_(false),
	  Selected0_(true),
	  Chapter_(0),
	  CurState_(TalkSelectActorState::Max)
{
	Chapter_ = dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).GetChapterCount();
}

TalkSelectActor::~TalkSelectActor()
{
}


void TalkSelectActor::Start()
{
	MyRenderer0_ = CreateRenderer();
	MyRenderer1_ = CreateRenderer();
	MyRenderer0_->CreateAnimation("Booper.bmp", "Booper", 0, 18, 0.1f);
	MyRenderer0_->CreateAnimation("Success.bmp", "Success", 0, 8, 0.1f, false);
	ChangeState(TalkSelectActorState::Booper);
	LevelRegist("TalkSelectActor");
}

void TalkSelectActor::Update()
{
	StateUpdate();
}


void TalkSelectActor::ChangeState(TalkSelectActorState _State)
{
	if (CurState_ == _State)
	{
		return;
	}
	switch (_State)
	{
	case TalkSelectActorState::Booper:
		BooperStart();
		break;
	case TalkSelectActorState::SelectActor:
		SelectActorStart();
		break;
	case TalkSelectActorState::Success:
		SuccessStart();
		break;
	case TalkSelectActorState::Max:
		break;
	default:
		break;
	}

	CurState_ = _State;
}

void TalkSelectActor::StateUpdate()
{
	switch (CurState_)
	{
	case TalkSelectActorState::Booper:
		BooperUpdate();
		break;
	case TalkSelectActorState::SelectActor:
		SelectActorUpdate();
		break;
	case TalkSelectActorState::Success:
		SuccessUpdate();
		break;
	case TalkSelectActorState::Max:
		break;
	default:
		break;
	}
}


void TalkSelectActor::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Chapter_ = dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).GetChapterCount();
}
