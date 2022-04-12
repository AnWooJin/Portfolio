#include "DevilSD.h"
#include <GameEngine/GameEngineRenderer.h>

DevilSD::DevilSD()
{
}

DevilSD::~DevilSD()
{
}


void DevilSD::Start()
{
}

void DevilSD::Update()
{

}

void DevilSD::Render()
{

}

void DevilSD::ImageSetting(int _ChapterLevel)
{
	switch (_ChapterLevel)
	{
	case 1:
	{
		{
			SetPosition({ 842,505 });
			GameEngineRenderer* Render = CreateRenderer("Chapter1Devil.bmp");
			Render->CreateAnimation("Chapter1Devil.bmp", "Chapter1Devil", 0, 11, 0.065f);
			Render->ChangeAnimation("Chapter1Devil");
		}

		{
			GameEngineRenderer* Render = CreateRenderer("LoveSign.bmp");
			Render->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Render->ChangeAnimation("LoveSign");
			Render->SetPivot({ -30, -20 });
		}
		break;
	}
	case 2:
	{
		{
			SetPosition({ 710,505 });
			GameEngineRenderer* Render = CreateRenderer("Chapter2_Devil.bmp");
			Render->CreateAnimation("Chapter2_Devil.bmp", "Chapter2_Devil", 0, 11, 0.065f);
			Render->ChangeAnimation("Chapter2_Devil");
		}

		{
			GameEngineRenderer* Render = CreateRenderer("LoveSign.bmp");
			Render->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Render->ChangeAnimation("LoveSign");
			Render->SetPivot({ -30, -20 });
		}
		break;
	}
	default:
		break;
	}
}