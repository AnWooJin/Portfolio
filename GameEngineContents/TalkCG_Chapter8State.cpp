#include "TalkCG_Chapter8.h"
#include "HellTakerGame.h"
#include "TalkExtraCG_Chapter8.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineWindow.h>

void TalkCG_Chapter8::IdleStart()
{
	if (MyRenderer_ != nullptr)
	{
		MyRenderer_->CreateAnimation("Chapter8CG_Idle.bmp", "Chapter8CG_Idle", 0, 9, 0.3f, false);
		MyRenderer_->ChangeAnimation("Chapter8CG_Idle");
	}
}

void TalkCG_Chapter8::SuccessStart()
{
	
}

void TalkCG_Chapter8::IdleUpdate()
{
	if (4 == MyRenderer_->CurrentAnimation()->WorldCurrentFrame() && false == IsCreateExtraActor_)
	{
		CreateExtraActor0();
		CreateExtraActor1();
		IsCreateExtraActor_ = true;
	}
	if (true == dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).GetIsSuccess())
	{
		ChangeState(TalkCGState_Chapter8::Success);
	}
}

void TalkCG_Chapter8::SuccessUpdate()
{
		
}

void TalkCG_Chapter8::CreateExtraActor0()
{
	TalkExtraCG_Chapter8* ExtraCG0 = GetLevel()->CreateActor<TalkExtraCG_Chapter8>(2);
	ExtraCG0->SetMovePos({ 360,250 });
	ExtraCG0->SetPosition({ 640,250 });
	

	

	
}

void TalkCG_Chapter8::CreateExtraActor1()
{
	TalkExtraCG_Chapter8* ExtraCG1 = GetLevel()->CreateActor<TalkExtraCG_Chapter8>(2);
	ExtraCG1->SetMovePos({ 900, 250 });
	ExtraCG1->SetPosition({ 1180,250 });
}