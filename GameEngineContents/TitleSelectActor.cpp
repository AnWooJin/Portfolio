#include "TitleSelectActor.h"
#include "TitleLevel.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineSound.h>

TitleSelectActor::TitleSelectActor()
	:MyRenderer0_(nullptr),
	MyRenderer1_(nullptr),
	CurState_(TitleSelectActorState::Max),
	IsSelected_(true)

{
}

TitleSelectActor::~TitleSelectActor()
{
}

void TitleSelectActor::Start()
{
	ChangeState(TitleSelectActorState::Booper);
}

void TitleSelectActor::Update()
{
	StateUpdate();
}


void TitleSelectActor::TitleImageChange()
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


void TitleSelectActor::ChangeState(TitleSelectActorState _State)
{
	if (CurState_ == _State)
	{
		return;
	}
	switch (_State)
	{
	case TitleSelectActorState::Booper:
		BooperStart();
		break;
	case TitleSelectActorState::SelectActor:
		SelectActorStart();
		break;
	case TitleSelectActorState::Max:
		break;
	default:
		break;
	}

	CurState_ = _State;
}

void TitleSelectActor::StateUpdate()
{
	switch (CurState_)
	{
	case TitleSelectActorState::Booper:
		BooperUpdate();
		break;
	case TitleSelectActorState::SelectActor:
		SelectActorUpdate();
		break;
	case TitleSelectActorState::Max:
		break;
	default:
		break;
	}
}