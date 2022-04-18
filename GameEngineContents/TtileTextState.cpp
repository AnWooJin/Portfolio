#include "TitleText.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>


void TitleText::TextStart()
{
	SetPosition({ 640, 598 });
	MyRenderer_ = CreateRenderer("TitleText.bmp");
	MyRenderer_->SetIndex(TitleLevel::TextPage_);
}

void TitleText::PrologueStart()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	MyRenderer_->SetImage("PrologueScene.bmp");
	MyRenderer_->SetIndex(0);
}

void TitleText::SceneChangerStart()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	MyRenderer_->CreateFolderAnimation("SceneChange", "SceneChange", 0, 28, 0.1f, false);
	MyRenderer_->ChangeAnimation("SceneChange");
	//GameEngineSound::SoundPlayOneShot()
}

void TitleText::TextUpdate()
{
	MyRenderer_->SetIndex(TitleLevel::TextPage_);
	if (TitleLevel::TextPage_ == 4)
	{
		ChangeState(TitleTextState::Prologue);
	}
}

void TitleText::PrologueUpdate()
{
	int Index = TitleLevel::TextPage_ - 4;
	MyRenderer_->SetIndex(Index);
	if (Index == 3)
	{
		ChangeState(TitleTextState::SceneChagnger);
	}
	
}

void TitleText::SceneChangerUpdate()
{
	if (true == MyRenderer_->IsEndAnimation())
	{
		GameEngine::GetInst().ChangeLevel("Play");
	}
}