#include "SideUI.h"
#include <GameEngine/GameEngineRenderer.h>

SideUI::SideUI()
	: MyPlayer_(nullptr)
{
}

SideUI::~SideUI()
{
}

void SideUI::Start()
{
	TextFont.Load("C:\\Users\\asus\\Desktop\\C++\\Portfolio\\Resource\\Font\\Segment7Standard.otf");

	MyPlayer_ = GetLevel()->FindActor<Player>("Player");
	CreateRenderer("SideUI.bmp");
	SetPosition({ 640,360 });
}

void SideUI::Update()
{
	
}

void SideUI::Render()
{
	int Count = MyPlayer_->GetMoveCount();
	if (Count <= 0)
	{
		TextFont.Draw("X", {110.0f, 515.0f}, RGB(255, 255, 255), 100, 50);
		return;
	}
	TextFont.Draw(std::to_string(Count), {110.0f, 515.0f}, RGB(255, 255, 255), 100, 50);
}