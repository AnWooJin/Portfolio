#include "TalkText.h"
#include "HellTakerGame.h"
#include "TalkLevel.h"
#include "TalkSelectActor.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>

void TalkText::IdleStart()
{
	ChapterTextSetting();
}

void TalkText::SuccessStart()
{
	ChapterTextSetting();
}

void TalkText::BadStart()
{
	ChapterTextSetting();
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

//////////////////  스테이지에 맞는 이미지로 세팅해 주는 함수

void TalkText::ChapterTextSetting()
{
	int Chapter = dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount();

	switch (Chapter)
	{
	case 1:
		Chapter1TextSetting();
		break;
	case 2:
		Chapter2TextSetting();
		break;
	case 3:
		Chapter3TextSetting();
		break;
	case 4:
		Chapter4TextSetting();
		break;
	case 5:
		Chapter5TextSetting();
		break;
	case 6:
		Chapter6TextSetting();
		break;
	case 7:
		Chapter7TextSetting();
		break;
	default:
		break;
	}
}

void TalkText::Chapter1TextSetting()
{
	switch (CurState_)
	{
	case TalkTextState::Idle:
		MyRenderer_->SetImage("Chapter1_TalkText.bmp");
		break;
	case TalkTextState::Success:
		MyRenderer_->SetImage("Chapter1_TalkText_Success.bmp");
		break;
	case TalkTextState::Bad:
		MyRenderer_->SetImage("Chapter1_TalkText_Bad.bmp");
		break;
	case TalkTextState::Max:
		break;
	default:
		break;
	}
}

void TalkText::Chapter2TextSetting()
{
	switch (CurState_)
	{
	case TalkTextState::Idle:
		MyRenderer_->SetImage("Chapter2_TalkText.bmp");
		break;
	case TalkTextState::Success:
		MyRenderer_->SetImage("Chapter2_TalkText_Success.bmp");
		break;
	case TalkTextState::Bad:
		MyRenderer_->SetImage("Chapter2_TalkText_Bad.bmp");
		break;
	case TalkTextState::Max:
		break;
	default:
		break;
	}
}

void TalkText::Chapter3TextSetting()
{
	switch (CurState_)
	{
	case TalkTextState::Idle:
		MyRenderer_->SetImage("Chapter3_TalkText.bmp");
		break;
	case TalkTextState::Success:
		MyRenderer_->SetImage("Chapter3_TalkText_Success.bmp");
		break;
	case TalkTextState::Bad:
		MyRenderer_->SetImage("Chapter3_TalkText_Bad.bmp");
		break;
	case TalkTextState::Max:
		break;
	default:
		break;
	}
}

void TalkText::Chapter4TextSetting()
{
	switch (CurState_)
	{
	case TalkTextState::Idle:
		MyRenderer_->SetImage("Chapter4_TalkText.bmp");
		break;
	case TalkTextState::Success:
		MyRenderer_->SetImage("Chapter4_TalkText_Success.bmp");
		break;
	case TalkTextState::Bad:
		MyRenderer_->SetImage("Chapter4_TalkText_Bad.bmp");
		break;
	case TalkTextState::Max:
		break;
	default:
		break;
	}
}

void TalkText::Chapter5TextSetting()
{
	switch (CurState_)
	{
	case TalkTextState::Idle:
		MyRenderer_->SetImage("Chapter5_TalkText.bmp");
		break;
	case TalkTextState::Success:
		MyRenderer_->SetImage("Chapter5_TalkText_Success.bmp");
		break;
	case TalkTextState::Bad:
		MyRenderer_->SetImage("Chapter5_TalkText_Bad.bmp");
		break;
	case TalkTextState::Max:
		break;
	default:
		break;
	}
}

void TalkText::Chapter6TextSetting()
{
	switch (CurState_)
	{
	case TalkTextState::Idle:
		MyRenderer_->SetImage("Chapter6_TalkText.bmp");
		break;
	case TalkTextState::Success:
		MyRenderer_->SetImage("Chapter6_TalkText_Success.bmp");
		break;
	case TalkTextState::Bad:
		MyRenderer_->SetImage("Chapter6_TalkText_Bad.bmp");
		break;
	case TalkTextState::Max:
		break;
	default:
		break;
	}
}

void TalkText::Chapter7TextSetting()
{
	switch (CurState_)
	{
	case TalkTextState::Idle:
		MyRenderer_->SetImage("Chapter7_TalkText.bmp");
		break;
	case TalkTextState::Success:
		MyRenderer_->SetImage("Chapter7_TalkText_Success.bmp");
		break;
	case TalkTextState::Max:
		break;
	default:
		break;
	}
}
