#include "DevilSD.h"
#include "HellTakerGame.h"
#include <GameEngine/GameEngine.h>
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

void DevilSD::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	if (8 == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount())
	{
		MyRenderer_->CameraEffectOn();
	}
	else
	{
		MyRenderer_->CameraEffectOff();
	}

}

void DevilSD::ImageSetting(int _ChapterLevel)
{
	switch (_ChapterLevel)
	{
	case 1:
	{
		{
			SetPosition({ 842,505 });
			MyRenderer_ = CreateRenderer("Chapter1Devil.bmp");
			MyRenderer_->CreateAnimation("Chapter1Devil.bmp", "Chapter1Devil", 0, 11, 0.065f);
			MyRenderer_->ChangeAnimation("Chapter1Devil");
		}

		{
			GameEngineRenderer* Renderer_ = CreateRenderer("LoveSign.bmp");
			Renderer_->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Renderer_->ChangeAnimation("LoveSign");
			Renderer_->SetPivot({ -30, -20 });
		}
		break;
	}
	case 2:
	{
		{
			SetPosition({ 710,505 });
			MyRenderer_ = CreateRenderer("Chapter2_Devil.bmp");
			MyRenderer_->CreateAnimation("Chapter2_Devil.bmp", "Chapter2_Devil", 0, 11, 0.065f);
			MyRenderer_->ChangeAnimation("Chapter2_Devil");
		}

		{
			GameEngineRenderer* Renderer_ = CreateRenderer("LoveSign.bmp");
			Renderer_->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Renderer_->ChangeAnimation("LoveSign");
			Renderer_->SetPivot({ -30, -20 });
		}
		break;
	}
	case 3:
	{
		{
			SetPosition({ 666,144 });
			MyRenderer_ = CreateRenderer("Chapter3_Devil.bmp");
			MyRenderer_->CreateAnimation("Chapter3_Devil.bmp", "Chapter3_Devil", 0, 11, 0.065f);
			MyRenderer_->ChangeAnimation("Chapter3_Devil");
		}

		{
			GameEngineRenderer* MyRenderer_ = CreateRenderer("Chapter3_Devil.bmp");
			MyRenderer_->CreateAnimation("Chapter3_Devil.bmp", "Chapter3_Devil", 0, 11, 0.065f);
			MyRenderer_->ChangeAnimation("Chapter3_Devil");
			MyRenderer_->SetPivot({ -64, 0 });
		}

		{
			GameEngineRenderer* MyRenderer_ = CreateRenderer("Chapter3_Devil.bmp");
			MyRenderer_->CreateAnimation("Chapter3_Devil.bmp", "Chapter3_Devil", 0, 11, 0.065f);
			MyRenderer_->ChangeAnimation("Chapter3_Devil");
			MyRenderer_->SetPivot({ 64, 0 });
		}

		{
			GameEngineRenderer* Renderer_ = CreateRenderer("LoveSign.bmp");
			Renderer_->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Renderer_->ChangeAnimation("LoveSign");
			Renderer_->SetPivot({ -30, -20 });
		}

		{
			GameEngineRenderer* Renderer_ = CreateRenderer("LoveSign.bmp");
			Renderer_->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Renderer_->ChangeAnimation("LoveSign");
			Renderer_->SetPivot({ -94, -20 });
		}

		{
			GameEngineRenderer* Renderer_ = CreateRenderer("LoveSign.bmp");
			Renderer_->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Renderer_->ChangeAnimation("LoveSign");
			Renderer_->SetPivot({ 34, -20 });
		}
		break;
	}
	case 4:
	{
		{
			SetPosition({ 875,350 });
			MyRenderer_ = CreateRenderer("Chapter4_Devil.bmp");
			MyRenderer_->CreateAnimation("Chapter4_Devil.bmp", "Chapter4_Devil", 0, 11, 0.065f);
			MyRenderer_->ChangeAnimation("Chapter4_Devil");
		}

		{
			GameEngineRenderer* Renderer_ = CreateRenderer("LoveSign.bmp");
			Renderer_->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Renderer_->ChangeAnimation("LoveSign");
			Renderer_->SetPivot({ -30, -20 });
		}
		break;
	}
	case 5:
	{
		{
			SetPosition({ 746,144 });
			MyRenderer_ = CreateRenderer("Chapter5_Devil.bmp");
			MyRenderer_->CreateAnimation("Chapter5_Devil.bmp", "Chapter5_Devil", 0, 11, 0.065f);
			MyRenderer_->ChangeAnimation("Chapter5_Devil");
		}

		{
			GameEngineRenderer* Renderer_ = CreateRenderer("LoveSign.bmp");
			Renderer_->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Renderer_->ChangeAnimation("LoveSign");
			Renderer_->SetPivot({ -30, -20 });
		}
		break;
	}
	case 6:
	{
		{
			SetPosition({ 776,576 });
			MyRenderer_ = CreateRenderer("Chapter6_Devil.bmp");
			MyRenderer_->CreateAnimation("Chapter6_Devil.bmp", "Chapter6_Devil", 0, 11, 0.065f);
			MyRenderer_->ChangeAnimation("Chapter6_Devil");
		}

		{
			GameEngineRenderer* Renderer_ = CreateRenderer("LoveSign.bmp");
			Renderer_->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Renderer_->ChangeAnimation("LoveSign");
			Renderer_->SetPivot({ -30, -20 });
		}
		break;
	}
	case 7:
	{
		{
			SetPosition({675,140 });
			MyRenderer_ = CreateRenderer("Chapter7_Devil.bmp");
			MyRenderer_->CreateAnimation("Chapter7_Devil.bmp", "Chapter7_Devil", 0, 11, 0.065f);
			MyRenderer_->ChangeAnimation("Chapter7_Devil");
		}

		{
			GameEngineRenderer* Renderer_ = CreateRenderer("LoveSign.bmp");
			Renderer_->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Renderer_->ChangeAnimation("LoveSign");
			Renderer_->SetPivot({ -30, -20 });
		}
		break;
	}
	case 8:
	{
		{
			SetPosition({ 640,416 });
			MyRenderer_ = CreateRenderer("Chapter8_Devil.bmp");
			MyRenderer_->CreateAnimation("Chapter8_Devil.bmp", "Chapter8_Devil", 0, 11, 0.065f);
			MyRenderer_->ChangeAnimation("Chapter8_Devil");
		}

		{
			GameEngineRenderer* Renderer_ = CreateRenderer("LoveSign.bmp");
			Renderer_->CameraEffectOn();
			Renderer_->CreateAnimation("LoveSign.bmp", "LoveSign", 0, 3, 0.1f);
			Renderer_->ChangeAnimation("LoveSign");
			Renderer_->SetPivot({ -30, -20 });
		}
		break;
	}
	default:
		break;
	}
}