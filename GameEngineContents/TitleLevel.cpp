#include "TitleLevel.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>
#include "BlackBackGround.h"
#include "TitleBackGround.h"
#include "TitleCG.h"
#include "TitleText.h"
#include "Transition.h"
#include "TitleSelectActor.h"
#include "Booper.h"

int TitleLevel::TextPage_ = 0;

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Loading()
{
	if (false == GameEngineInput::GetInst()->IsKey("Next"))
	{
		GameEngineInput::GetInst()->CreateKey("Next", VK_SPACE);
	}

	CreateActor<BlackBackGround>(0);
	CreateActor<TitleBackGround>(1);
	CreateActor<TitleCG>(2);
	CreateActor<TitleText>(3);
	CreateActor<TitleSelectActor>(3);
	SetCameraPos({ 680, 0 });

}

void TitleLevel::Update()
{
	MoveCameraPos(float4::LEFT * 0.2f);
	if (GetCameraPos().x <= 0.0f)
	{
		SetCameraPos({ 680,0 });
	}
	if (true == GameEngineInput::GetInst()->IsDown("Next") && TextPage_ <= 6)
	{
		++TextPage_;
		GameEngineSound::SoundPlayOneShot("dialogue_text_end_01.wav");
	}

}

void TitleLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	SetCameraPos({ 680, 0 });
	CreateActor<TitleSelectActor>(3);
	TitleBgmPlayer_ = GameEngineSound::SoundPlayControl("TitleBGM.wav");
	TextPage_ = 0;
}

void TitleLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	TitleBgmPlayer_.Stop();
}
