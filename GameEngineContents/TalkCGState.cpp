#include "TalkLevel.h"
#include "TalkCG.h"
#include "HellTakerGame.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineWindow.h>

void TalkCG::NomalStart()
{
	TalkCGSetting(Chapter_);
}

void TalkCG::SuccessStart()
{
	TalkCGSetting(Chapter_);
}



void TalkCG::NomalUpdate()
{
	if (true == dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).GetIsSuccess())
	{
		ChangeState(TalkCGState::Success);
	}
}


void TalkCG::SuccessUpdate()
{

	if (3 == dynamic_cast<TalkLevel*>(GetLevel())->GetTextPage())
	{
		GameEngine::GetInst().ChangeLevel("Play");
	}
}

void TalkCG::TalkCGSetting(int _Chapter)
{
	switch (_Chapter)
	{
	case 1:
		Chapter1ImageSetting();
		break;
	case 2:
		Chapter2ImageSetting();
		break;
	case 3:
		Chapter3ImageSetting();
		break;
	case 4:
		Chapter4ImageSetting();
	default:
		break;
	}
}

//////////////////////////    챕터별로 이미지를 지정해주는 함수

void TalkCG::Chapter1ImageSetting()
{
	SetPosition({ 640, 250 });
	switch (CurState_)
	{
	case TalkCGState::Nomal:
		MyRenderer_->SetImage("Chapter1CG_Nomal.bmp");
		break;
	case TalkCGState::Success:
		MyRenderer_->SetImage("Chapter1CG_Success.bmp");
		break;
	default:
		break;
	}
}

void TalkCG::Chapter2ImageSetting()
{
	SetPosition({ 640, 250 });
	switch (CurState_)
	{
	case TalkCGState::Nomal:
		MyRenderer_->SetImage("Chapter2CG_Nomal.bmp");
		break;
	case TalkCGState::Success:
		MyRenderer_->SetImage("Chapter2CG_Success.bmp");
		break;
	default:
		break;
	}
}

void TalkCG::Chapter3ImageSetting()
{
	SetPosition({ 640, 250 });
	switch (CurState_)
	{
	case TalkCGState::Nomal:
		MyRenderer_->SetImage("Chapter3CG_Nomal.bmp");
		break;
	case TalkCGState::Success:
		MyRenderer_->SetImage("Chapter3CG_Success.bmp");
		break;
	default:
		break;
	}
}

void TalkCG::Chapter4ImageSetting()
{
	SetPosition({ 640, 250 });
	switch (CurState_)
	{
	case TalkCGState::Nomal:
		MyRenderer_->SetImage("Chapter3CG_Nomal.bmp");
		break;
	case TalkCGState::Success:
		MyRenderer_->SetImage("Chapter3CG_Success.bmp");
		break;
	default:
		break;
	}
}
