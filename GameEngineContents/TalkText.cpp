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































//////////////////  스테이지에 맞는 이미지로 세팅해 주는 함수

void TalkText::ChapterIdleSetting()
{
	int Chapter = dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount();

	switch (Chapter)
	{
	case 1:
		MyRenderer_->SetImage("Chapter1_TalkText.bmp");
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}


