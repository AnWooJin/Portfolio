#include "SideUI.h"
#include "HellTakerGame.h"
#include "GameEngine/GameEngine.h"
#include <GameEngine/GameEngineRenderer.h>

SideUI::SideUI()
	: MyPlayer_(nullptr)
	, Chapter_(0)
{
}

SideUI::~SideUI()
{
}

void SideUI::Start()
{
	TextFont.Load("..\\Resource\\Font\\Segment7Standard.otf");

	MyPlayer_ = GetLevel()->FindActor<Player>("Player");
	CreateRenderer("SideUI.bmp");
	SetPosition({ 640,360 });
}

void SideUI::Update()
{
	
}

void SideUI::Render()
{
	if (true == MyPlayer_->IsPlayerDeath())
	{
		return;
	}
	ChapterRender();
	int Count = MyPlayer_->GetMoveCount();
	if (Count < 0)
	{
		return;
	}
	if (Count == 0)
	{
		TextFont.Draw("X", {110.0f, 515.0f}, RGB(255, 255, 255), 100, 50);
		return;
	}
	if (Count >= 10)
	{
		TextFont.Draw(std::to_string(Count), { 80.0f, 515.0f }, RGB(255, 255, 255), 100, 50);
		return;
	}
	
	TextFont.Draw(std::to_string(Count), {110.0f, 515.0f}, RGB(255, 255, 255), 100, 50);
}

void SideUI::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Chapter_ = dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount();
}

void SideUI::ChapterRender()
{
	switch (Chapter_)
	{
	case 1:
		TextFont.Draw("グ", { 1100.0f, 515.0f }, RGB(255, 255, 255), 100, 50);
		break;
	case 2:
		TextFont.Draw("ケ", { 1100.0f, 515.0f }, RGB(255, 255, 255), 100, 50);
		break;
	case 3:
		TextFont.Draw("ゲ", { 1100.0f, 515.0f }, RGB(255, 255, 255), 100, 50);
		break;
	case 4:
		TextFont.Draw("コ", { 1100.0f, 515.0f }, RGB(255, 255, 255), 100, 50);
		break;
	case 5:
		TextFont.Draw("ゴ", { 1100.0f, 515.0f }, RGB(255, 255, 255), 100, 50);
		break;
	case 6:
		TextFont.Draw("サ", { 1100.0f, 515.0f }, RGB(255, 255, 255), 100, 50);
		break;
	case 7:
		TextFont.Draw("ザ", { 1100.0f, 515.0f }, RGB(255, 255, 255), 100, 50);
		break;
	case 8:
		TextFont.Draw("シ", { 1100.0f, 515.0f }, RGB(255, 255, 255), 100, 50);
		break;
	default:
		break;
	}
}