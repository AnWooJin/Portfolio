#include "Booper.h"
#include "TitleLevel.h"
#include <GameEngine/GameEngineRenderer.h>

Booper::Booper()
{
}

Booper::~Booper()
{
}

void Booper::Start()
{
	SetPosition({ 640, 630 });
	MyRenderer_ = CreateRenderer();
	MyRenderer_->CreateAnimation("Booper.bmp", "Booper", 0, 18, 0.1f);
	MyRenderer_->ChangeAnimation("Booper");

}

void Booper::Update()
{
	if (TitleLevel::TextPage_ == 2)
	{
		MyRenderer_->Off();
	}
	else
	{
		MyRenderer_->On();
	}
}