#include "TitleText.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>

TitleText::TitleText()
	: MyRenderer_(nullptr),
	 TextPage_(0)
{
}

TitleText::~TitleText()
{
}

void TitleText::Start()
{

	SetPosition({ 640, 598 });
	MyRenderer_ = CreateRenderer("TitleText_1.bmp");
	MyRenderer_->SetIndex(TextPage_);

	if (false == GameEngineInput::GetInst()->IsKey("Next"))
	{
		GameEngineInput::GetInst()->CreateKey("Next", VK_SPACE);
	}
}

void TitleText::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Next"))
	{
		++TextPage_;
		if (TextPage_ >= 2)
		{
			MyRenderer_->SetImage("TitleText01.bmp");
			return;
		}
		MyRenderer_->SetIndex(TextPage_);
	}
	
}