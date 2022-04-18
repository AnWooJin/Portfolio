#include "TalkCG.h"
#include <GameEngine/GameEngineRenderer.h>

TalkCG::TalkCG()
	: MyRenderer_(nullptr),
	CurState_(TalkCGState::Max)
{
}

TalkCG::~TalkCG()
{
}

void TalkCG::Start()
{
	ChangeState(TalkCGState::Nomal);
}

void TalkCG::Update()
{
	StateUpdate();
}

void TalkCG::ChangeState(TalkCGState _State)
{
	if (CurState_ == _State)
	{
		return;
	}
	switch (_State)
	{
	case TalkCGState::Nomal:
		NomalStart();
		break;
	case TalkCGState::Success:
		SuccessStart();
		break;
	case TalkCGState::Max:
		break;
	default:
		break;
	}
	CurState_ = _State;
}

void TalkCG::StateUpdate()
{
	switch (CurState_)
	{
	case TalkCGState::Nomal:
		NomalUpdate();
		break;
	case TalkCGState::Success:
		SuccessUpdate();
		break;
	case TalkCGState::Max:
		break;
	default:
		break;
	}
}