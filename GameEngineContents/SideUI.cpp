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
	TextFont.Load("arial.ttf");

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



	//TextFont.Draw("23", {100.0f, 620.0f}, 100, 50);
}