#include "TalkCG.h"
#include "HellTakerGame.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>

TalkCG::TalkCG()
	: MyRenderer_(nullptr),
	  Chapter_(0),
	  CurState_(TalkCGState::Max)
{
	Chapter_ = dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).GetChapterCount();
}

TalkCG::~TalkCG()
{
}

void TalkCG::Start()
{
	MyRenderer_ = CreateRenderer();
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
	CurState_ = _State;
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



void TalkCG::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Chapter_ = dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).GetChapterCount();
	//ChangeState(TalkCGState::Nomal);
}