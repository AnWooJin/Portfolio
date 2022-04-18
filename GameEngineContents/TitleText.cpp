#include "TitleText.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>

TitleText::TitleText()
	: MyRenderer_(nullptr),
	CurState_(TitleTextState::Text)
{
}

TitleText::~TitleText()
{
}

void TitleText::Start()
{
	TextStart();
}

void TitleText::Update()
{
	StateUpdate();
}

void TitleText::ChangeState(TitleTextState _State)
{
	if (CurState_ == _State)
	{
		return;
	}
	switch (_State)
	{
	case Text:
		TextStart();
		break;
	case Prologue:
		PrologueStart();
		break;
	case SceneChagnger:
		SceneChangerStart();
		break;
	case Max:
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
	case Text:
		TextUpdate();
		break;
	case Prologue:
		PrologueUpdate();
		break;
	case SceneChagnger:
		SceneChangerUpdate();
		break;
	case Max:
		break;
	default:
		break;
	}
}