#include "TitleText.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>

TitleText::TitleText()
	: MyRenderer_(nullptr),
	  PlayOpenSound_(false),
	  PlayCloseSound_(false),
	CurState_(TitleTextState::Max)
{
}

TitleText::~TitleText()
{
}

void TitleText::Start()
{
	ChangeState(TitleTextState::Text);
}

void TitleText::Update()
{
	StateUpdate();
}

void TitleText::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	PlayOpenSound_ = false;
	PlayCloseSound_ = false;
	ChangeState(TitleTextState::Text);
}

void TitleText::ChangeState(TitleTextState _State)
{
	if (CurState_ == _State)
	{
		return;
	}
	switch (_State)
	{
	case TitleTextState::Text:
		TextStart();
		break;
	case TitleTextState::Prologue:
		PrologueStart();
		break;
	case TitleTextState::SceneChagnger:
		SceneChangerStart();
		break;
	case TitleTextState::Max:
		break;
	default:
		break;
	}

	CurState_ = _State;
}

void TitleText::StateUpdate()
{
	switch (CurState_)
	{
	case TitleTextState::Text:
		TextUpdate();
		break;
	case TitleTextState::Prologue:
		PrologueUpdate();
		break;
	case TitleTextState::SceneChagnger:
		SceneChangerUpdate();
		break;
	case TitleTextState::Max:
		break;
	default:
		break;
	}
}