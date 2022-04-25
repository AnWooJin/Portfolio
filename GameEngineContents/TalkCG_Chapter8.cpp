#include "TalkCG_Chapter8.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>


TalkCG_Chapter8::TalkCG_Chapter8()
	: MyRenderer_(nullptr),
	  CurState_(TalkCGState_Chapter8::Max),
	  IsCreateExtraActor_(false)
{
}

TalkCG_Chapter8::~TalkCG_Chapter8()
{
}

void TalkCG_Chapter8::Start()
{
	SetPosition({ 640, 238 });
	ChangeState(TalkCGState_Chapter8::Animation);
}

void TalkCG_Chapter8::Update()
{
	StateUpdate();
}

void TalkCG_Chapter8::ChangeState(TalkCGState_Chapter8 _State)
{
	if (CurState_ == _State)
	{
		return;
	}
	CurState_ = _State;
	
	switch (_State)
	{
	case TalkCGState_Chapter8::Animation:
		AnimationStart();
		break;
	case TalkCGState_Chapter8::Idle:
		IdleStart();
		break;
	case TalkCGState_Chapter8::Success0:
		Success0Start();
		break;
	case TalkCGState_Chapter8::Success1:
		Success1Start();
		break;
	case TalkCGState_Chapter8::Max:
		break;
	default:
		break;
	}
}

void TalkCG_Chapter8::StateUpdate()
{
	switch (CurState_)
	{
	case TalkCGState_Chapter8::Animation:
		AnimationUpdate();
		break;
	case TalkCGState_Chapter8::Idle:
		IdleUpdate();
		break;
	case TalkCGState_Chapter8::Success0:
		Success0Update();
		break;
	case TalkCGState_Chapter8::Success1:
		Success1Update();
		break;
	case TalkCGState_Chapter8::Max:
		break;
	default:
		break;
	}
}



void TalkCG_Chapter8::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}