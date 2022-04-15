#include "TitleText.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>

TitleText::TitleText()
	: MyRenderer_(nullptr)
{
}

TitleText::~TitleText()
{
}

void TitleText::Start()
{

	SetPosition({ 640, 598 });
	MyRenderer_ = CreateRenderer("TitleText_1.bmp");
	MyRenderer_->SetIndex(TitleLevel::TextPage_);

}

void TitleText::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Next"))
	{

		if (TitleLevel::TextPage_ >= 2)
		{
			MyRenderer_->SetImage("TitleText01.bmp");
			return;
		}
		MyRenderer_->SetIndex(TitleLevel::TextPage_);
	}



}