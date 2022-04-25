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
	ChangeState(TalkTextState::Idle);
	ChapterTextSetting();
}

void TalkText::Update()
{
	StateUpdate();
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




