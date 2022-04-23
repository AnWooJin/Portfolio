#include "TalkBackGround_Chapter8.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineWindow.h>

TalkBackGround_Chapter8::TalkBackGround_Chapter8()
	: MyRenderer_(nullptr),
	BlackRenderer_(nullptr)
{
}

TalkBackGround_Chapter8::~TalkBackGround_Chapter8()
{
}

void TalkBackGround_Chapter8::Start()
{
	SetPosition({ 640,300 });
	if (nullptr == MyRenderer_)
	{
		MyRenderer_ = CreateRenderer("TalkBG_Chapter8.bmp");
		BlackRenderer_ = CreateRenderer("BlackBG.bmp");
	}
	else
	{
		MyRenderer_->SetImage("TalkBG_Chapter8.bmp");
		BlackRenderer_->SetImage("BlackBG.bmp");
	}
	BlackRenderer_->SetOrder(0);
	BlackRenderer_->SetPivot({ 0, -100 });
}

void TalkBackGround_Chapter8::Update()
{
}
