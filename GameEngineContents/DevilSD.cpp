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
	case 3:
	{
		{
			SetPosition({ 666,144 });
			GameEngineRenderer* Render = CreateRenderer("Chapter3_Devil.bmp");
			Render->CreateAnimation("Chapter3_Devil.bmp", "Chapter3_Devil", 0, 11, 0.065f);
			Render->ChangeAnimation("Chapter3_Devil");
		}

		{
			GameEngineRenderer* Render = CreateRenderer("Chapter3_Devil.bmp");
			Render->CreateAnimation("Chapter3_Devil.bmp", "Chapter3_Devil", 0, 11, 0.065f);
			Render->ChangeAnimation("Chapter3_Devil");
			Render->SetPivot({ -64, 0 });
		}

		{
			GameEngineRenderer* Render = CreateRenderer("Chapter3_Devil.bmp");
			Render->CreateAnimation("Chapter3_Devil.bmp", "Chapter3_Devil", 0, 11, 0.065f);
			Render->ChangeAnimation("Chapter3_Devil");
			Render->SetPivot({ 64, 0 });
		}

		{
			GameEngineRenderer* Render = CreateRenderer("LoveSign.bmp");
			Render->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Render->ChangeAnimation("LoveSign");
			Render->SetPivot({ -30, -20 });
		}

		{
			GameEngineRenderer* Render = CreateRenderer("LoveSign.bmp");
			Render->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Render->ChangeAnimation("LoveSign");
			Render->SetPivot({ -94, -20 });
		}

		{
			GameEngineRenderer* Render = CreateRenderer("LoveSign.bmp");
			Render->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Render->ChangeAnimation("LoveSign");
			Render->SetPivot({ 34, -20 });
		}
		break;
	}
	case 4:
	{
		{
			SetPosition({ 875,350 });
			GameEngineRenderer* Render = CreateRenderer("Chapter4_Devil.bmp");
			Render->CreateAnimation("Chapter4_Devil.bmp", "Chapter4_Devil", 0, 11, 0.065f);
			Render->ChangeAnimation("Chapter4_Devil");
		}

		{
			GameEngineRenderer* Render = CreateRenderer("LoveSign.bmp");
			Render->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Render->ChangeAnimation("LoveSign");
			Render->SetPivot({ -30, -20 });
		}
		break;
	}
	case 5:
	{
		{
			SetPosition({ 746,144 });
			GameEngineRenderer* Render = CreateRenderer("Chapter5_Devil.bmp");
			Render->CreateAnimation("Chapter5_Devil.bmp", "Chapter5_Devil", 0, 11, 0.065f);
			Render->ChangeAnimation("Chapter5_Devil");
		}

		{
			GameEngineRenderer* Render = CreateRenderer("LoveSign.bmp");
			Render->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Render->ChangeAnimation("LoveSign");
			Render->SetPivot({ -30, -20 });
		}
		break;
	}
	case 6:
	{
		{
			SetPosition({ 776,576 });
			GameEngineRenderer* Render = CreateRenderer("Chapter6_Devil.bmp");
			Render->CreateAnimation("Chapter6_Devil.bmp", "Chapter6_Devil", 0, 11, 0.065f);
			Render->ChangeAnimation("Chapter6_Devil");
		}

		{
			GameEngineRenderer* Render = CreateRenderer("LoveSign.bmp");
			Render->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Render->ChangeAnimation("LoveSign");
			Render->SetPivot({ -30, -20 });
		}
		break;
	}
	case 7:
	{
		{
			SetPosition({675,140 });
			GameEngineRenderer* Render = CreateRenderer("Chapter7_Devil.bmp");
			Render->CreateAnimation("Chapter7_Devil.bmp", "Chapter7_Devil", 0, 11, 0.065f);
			Render->ChangeAnimation("Chapter7_Devil");
		}

		{
			GameEngineRenderer* Render = CreateRenderer("LoveSign.bmp");
			Render->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Render->ChangeAnimation("LoveSign");
			Render->SetPivot({ -30, -20 });
		}
		break;
	}
	case 8:
	{
		{
			SetPosition({ 710,505 });
			GameEngineRenderer* Render = CreateRenderer("Chapter8_Devil.bmp");
			Render->CreateAnimation("Chapter8_Devil.bmp", "Chapter8_Devil", 0, 11, 0.065f);
			Render->ChangeAnimation("Chapter8_Devil");
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