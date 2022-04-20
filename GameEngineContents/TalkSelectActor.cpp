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
