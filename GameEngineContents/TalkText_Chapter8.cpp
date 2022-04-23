#include "TalkText_Chapter8.h"
#include "Talk_Chapter8Level.h"
#include "HellTakerGame.h"
#include <GameEngine/GameEngineRenderer.h>

TalkText_Chapter8::TalkText_Chapter8()
	: MyRenderer_(nullptr),
	CurState_(TalkText_Chapter8State::Max)
{
}

TalkText_Chapter8::~TalkText_Chapter8()
{
}

void TalkText_Chapter8::Start()
{
	ChangeState(TalkText_Chapter8State::Empty);
}

void TalkText_Chapter8::Update()
{
	StateUpdate();
}

void TalkText_Chapter8::ChangeState(TalkText_Chapter8State _State)
{
	if (CurState_ == _State)
	{
		return;
	}
	switch (_State)
	{
	case TalkText_Chapter8State::Empty:
		EmptyStart();
	case TalkText_Chapter8State::Idle:
		IdleStart();
		break;
	case TalkText_Chapter8State::Bad0:
		Bad0Start();
		break;
	case TalkText_Chapter8State::Bad1:
		Bad1Start();
		break;
	case TalkText_Chapter8State::Max:
		break;
	default:
		break;
	}
}