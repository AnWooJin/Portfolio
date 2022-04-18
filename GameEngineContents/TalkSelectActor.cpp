#include "TalkSelectActor.h"
#include "TalkLevel.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineSound.h>

TalkSelectActor::TalkSelectActor()
	: MyRenderer0_(nullptr),
 	  MyRenderer1_(nullptr),
	  IsSelected_(true),
	  CurState_(TalkSelectActorState::Max)
{
}

TalkSelectActor::~TalkSelectActor()
{
}


void TalkSelectActor::Start()
{
	ChangeState(TalkSelectActorState::Booper);
}

void TalkSelectActor::Update()
{
	StateUpdate();
}


void TalkSelectActor::TitleImageChange()
{
	IsSelected_ = !IsSelected_;
	GameEngineSound::SoundPlayOneShot("button_menu_highlight_01.wav");
	if (IsSelected_ == true)
	{
		MyRenderer0_->SetImage("NewGame_Selected.bmp");
		MyRenderer1_->SetImage("Exit_UnSelected.bmp");
	}
	else
	{
		MyRenderer0_->SetImage("NewGame_UnSelected.bmp");
		MyRenderer1_->SetImage("Exit_Selected.bmp");
	}
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