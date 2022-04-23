#include "TalkBackGround.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineWindow.h>



TalkBackGround::TalkBackGround()
	:MyRenderer_(nullptr),
	BlackRenderer_(nullptr)
{
}

TalkBackGround::~TalkBackGround()
{
}

void TalkBackGround::Start()
{
	SetPosition({640,300});
	if (nullptr == MyRenderer_)
	{
		MyRenderer_ = CreateRenderer("TalkBG.bmp");
		BlackRenderer_ = CreateRenderer("BlackBG.bmp");
	}
	else
	{
		MyRenderer_->SetImage("TalkBG.bmp");
		BlackRenderer_->SetImage("BlackBG.bmp");
	}
	BlackRenderer_->SetOrder(0);
	BlackRenderer_->SetPivot({ 0, -100 });
}

void TalkBackGround::Update()
{
}
