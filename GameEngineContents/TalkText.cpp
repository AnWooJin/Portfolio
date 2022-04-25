#include "TalkText.h"
#include "TalkLevel.h"
#include "HellTakerGame.h"
#include <GameEngine/GameEngineRenderer.h>

TalkText::TalkText()
	: MyRenderer_(nullptr),
	CurState_(TalkTextState::Max)
{
}

TalkText::~TalkText()
{
}

void TalkText::Start()
{
	SetPosition({ 640, 598 });
	MyRenderer_ = CreateRenderer();
	ChangeState(TalkTextState::Idle);
}

void TalkText::Update()
{
	StateUpdate();
}




void TalkText::ChangeState(TalkTextState _State)
{
	if (CurState_ == _State)
	{
		return;
	}
	switch (_State)
	{
	case TalkTextState::Idle:
		IdleStart();
		break;
	case TalkTextState::Success:
		SuccessStart();
		break;
	case TalkTextState::Bad:
		BadStart();
		break;
	case TalkTextState::Max:
		break;
	default:
		break;
	}
	CurState_ = _State;
}

void TalkText::StateUpdate()
{
	switch (CurState_)
	{
	case TalkTextState::Idle:
		IdleUpdate();
		break;
	case TalkTextState::Success:
		SuccessUpdate();
		break;
	case TalkTextState::Bad:
		BadUpdate();
		break;
	case TalkTextState::Max:
		break;
	default:
		break;
	}
}




