#include "DevilSD.h"
#include "ClearEffect.h"
#include "HellTakerGame.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineSound.h>

DevilSD::DevilSD()
	: MyRenderer_(nullptr)
	, MyRenderer1_(nullptr)
	, MyRenderer2_(nullptr)
	, FilterRenderer_(nullptr)
	, FilterRenderer1_(nullptr)
	, FilterRenderer2_(nullptr)
	, IsEffect_(false)
	, SoundPlay_(false)
	, Time_(0.0f)
	, Chapter_(0)
{
}

DevilSD::~DevilSD()
{
}


void DevilSD::Start()
{
	CreateCollision("Devil", { 20,20 });
}

void DevilSD::Update()
{
	if (true == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetIsSuccess())
	{
		if (false == SoundPlay_)
		{
			GameEngineSound::SoundPlayOneShot("Clear.wav");
			SoundPlay_ = true;
		}
		ChapterSucess();
	}
	if (Time_ >= 1.0f)
	{
		CreateClearEffect();
		Death();
	}

}

void DevilSD::Render()
{

}


void DevilSD::CreateClearEffect()
{
	if (3 == Chapter_)
	{
		{
			GameEngineActor* Actor = GetLevel()->CreateActor<ClearEffect>(7);
			Actor->SetPosition(GetPosition() + (float4::LEFT * 64));
		}
		
		{
			GameEngineActor* Actor = GetLevel()->CreateActor<ClearEffect>(7);
			Actor->SetPosition(GetPosition());
		}

		{
			GameEngineActor* Actor = GetLevel()->CreateActor<ClearEffect>(7);
			Actor->SetPosition(GetPosition() + (float4::RIGHT * 64));
		}
	}
	else
	{
		GameEngineActor* Actor = GetLevel()->CreateActor<ClearEffect>(7);
		Actor->SetPosition(GetPosition());
	}
	
}


void DevilSD::ChapterSucess()
{
	if (3 == Chapter_)
	{
		Chapter3Sucess();
	}
	else
	{
		elseChapterSucess();
	}
}

void DevilSD::Chapter3Sucess()
{
	Time_ += GameEngineTime::GetDeltaTime();
	if (Time_ <= 1.0f)
	{
		FilterRenderer_->SetAlpha(static_cast<unsigned int>(GameEngineMath::LerpLimit(0, 255, Time_)));
	}
	if (Time_ <= 1.0f)
	{
		FilterRenderer1_->SetAlpha(static_cast<unsigned int>(GameEngineMath::LerpLimit(0, 255, Time_)));
	}
	if (Time_ <= 1.0f)
	{
		FilterRenderer2_->SetAlpha(static_cast<unsigned int>(GameEngineMath::LerpLimit(0, 255, Time_)));
		return;
	}

}

void DevilSD::elseChapterSucess()
{
	Time_ += GameEngineTime::GetDeltaTime();
	if (Time_ <= 1.0f)
	{
		FilterRenderer_->SetAlpha(static_cast<unsigned int>(GameEngineMath::LerpLimit(0, 255, Time_)));
		return;
	}
}


void DevilSD::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Time_ = 0.0f;
	Chapter_ = dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount();
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
			MyRenderer_ = CreateRenderer("Chapter1_Devil.bmp");
			MyRenderer_->CreateAnimation("Chapter1_Devil.bmp", "Chapter1_Devil", 0, 11, 0.065f);
			MyRenderer_->ChangeAnimation("Chapter1_Devil");
			FilterRenderer_ = CreateRenderer("Chapter1_Devil_Filter.bmp");
			FilterRenderer_->CreateAnimation("Chapter1_Devil_Filter.bmp", "Chapter1_Devil_Filter", 0, 11, 0.065f);
			FilterRenderer_->ChangeAnimation("Chapter1_Devil_Filter");
			FilterRenderer_->SetAlpha(0);
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
			FilterRenderer_ = CreateRenderer("Chapter2_Devil_Filter.bmp");
			FilterRenderer_->CreateAnimation("Chapter2_Devil_Filter.bmp", "Chapter2_Devil_Filter", 0, 11, 0.065f);
			FilterRenderer_->ChangeAnimation("Chapter2_Devil_Filter");
			FilterRenderer_->SetAlpha(0);
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
			FilterRenderer_ = CreateRenderer("Chapter3_Devil_Filter.bmp");
			FilterRenderer_->CreateAnimation("Chapter3_Devil_Filter.bmp", "Chapter3_Devil_Filter", 0, 11, 0.065f);
			FilterRenderer_->ChangeAnimation("Chapter3_Devil_Filter");
			FilterRenderer_->SetAlpha(0);
		}

		{
			MyRenderer1_ = CreateRenderer("Chapter3_Devil.bmp");
			MyRenderer1_->CreateAnimation("Chapter3_Devil.bmp", "Chapter3_Devil", 0, 11, 0.065f);
			MyRenderer1_->ChangeAnimation("Chapter3_Devil");
			MyRenderer1_->SetPivot({ -64, 0 });
			FilterRenderer1_ = CreateRenderer("Chapter3_Devil_Filter.bmp");
			FilterRenderer1_->CreateAnimation("Chapter3_Devil_Filter.bmp", "Chapter3_Devil_Filter", 0, 11, 0.065f);
			FilterRenderer1_->ChangeAnimation("Chapter3_Devil_Filter");
			FilterRenderer1_->SetAlpha(0);
		}

		{
			MyRenderer2_ = CreateRenderer("Chapter3_Devil.bmp");
			MyRenderer2_->CreateAnimation("Chapter3_Devil.bmp", "Chapter3_Devil", 0, 11, 0.065f);
			MyRenderer2_->ChangeAnimation("Chapter3_Devil");
			MyRenderer2_->SetPivot({ 64, 0 });
			FilterRenderer2_ = CreateRenderer("Chapter3_Devil_Filter.bmp");
			FilterRenderer2_->CreateAnimation("Chapter3_Devil_Filter.bmp", "Chapter3_Devil_Filter", 0, 11, 0.065f);
			FilterRenderer2_->ChangeAnimation("Chapter3_Devil_Filter");
			FilterRenderer2_->SetAlpha(0);
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
			FilterRenderer_ = CreateRenderer("Chapter4_Devil_Filter.bmp");
			FilterRenderer_->CreateAnimation("Chapter4_Devil_Filter.bmp", "Chapter4_Devil_Filter", 0, 11, 0.065f);
			FilterRenderer_->ChangeAnimation("Chapter4_Devil_Filter");
			FilterRenderer_->SetAlpha(0);			 
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
			FilterRenderer_ = CreateRenderer("Chapter5_Devil_Filter.bmp");
			FilterRenderer_->CreateAnimation("Chapter5_Devil_Filter.bmp", "Chapter5_Devil_Filter", 0, 11, 0.065f);
			FilterRenderer_->ChangeAnimation("Chapter5_Devil_Filter");
			FilterRenderer_->SetAlpha(0);
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
			FilterRenderer_ = CreateRenderer("Chapter6_Devil_Filter.bmp");
			FilterRenderer_->CreateAnimation("Chapter6_Devil_Filter.bmp", "Chapter6_Devil_Filter", 0, 11, 0.065f);
			FilterRenderer_->ChangeAnimation("Chapter6_Devil_Filter");
			FilterRenderer_->SetAlpha(0);
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
			FilterRenderer_ = CreateRenderer("Chapter7_Devil_Filter.bmp");
			FilterRenderer_->CreateAnimation("Chapter7_Devil_Filter.bmp", "Chapter7_Devil_Filter", 0, 11, 0.065f);
			FilterRenderer_->ChangeAnimation("Chapter7_Devil_Filter");
			FilterRenderer_->SetAlpha(0);
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
			FilterRenderer_ = CreateRenderer("Chapter8_Devil_Filter.bmp");
			FilterRenderer_->CreateAnimation("Chapter8_Devil_Filter.bmp", "Chapter8_Devil_Filter", 0, 11, 0.065f);
			FilterRenderer_->ChangeAnimation("Chapter8_Devil_Filter");
			FilterRenderer_->SetAlpha(0);
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