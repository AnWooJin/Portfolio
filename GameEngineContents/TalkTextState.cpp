#include "TalkText.h"
#include "HellTakerGame.h"
#include "TalkLevel.h"
#include "TalkSelectActor.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>

void TalkText::IdleStart()
{
	SetPosition({ 640, 598 });
	if (MyRenderer_ == nullptr)
	{
		MyRenderer_ = CreateRenderer("Chapter1_TalkText.bmp");
	}
	else
	{
		MyRenderer_->SetImage("Chapter1_TalkText.bmp");
	}
}

void TalkText::SuccessStart()
{
	MyRenderer_->SetImage("Chapter1_TalkText_Success.bmp");
}

void TalkText::BadStart()
{
	MyRenderer_->SetImage("Chapter1_TalkText_Bad.bmp");
}


void TalkText::IdleUpdate()
{
	TalkSelectActor* SelectActor = GetLevel()->FindActor<TalkSelectActor>("TalkSelectActor");
	bool IsSuccess = dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).GetIsSuccess();
	bool IsSelect = SelectActor->GetIsSelect();
	if (true == IsSuccess && true == IsSelect)
	{
		ChangeState(TalkTextState::Success);
	}
	else if (false == IsSuccess && true == IsSelect)
	{
		ChangeState(TalkTextState::Bad);
	}
}


void TalkText::SuccessUpdate()
{

}

void TalkText::BadUpdate()
{

}
