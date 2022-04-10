#include "DevilSD.h"
#include <GameEngine/GameEngineRenderer.h>

DevilSD::DevilSD()
	: ChapterLevel_(1)
{
}

DevilSD::~DevilSD()
{
}


void DevilSD::Start()
{
	ImageSetting(ChapterLevel_);
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
	}
		break;

	default:
		break;
	}
}