#include "TitleLevel.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>
#include "BlackBackGround.h"
#include "TitleBackGround.h"
#include "TitleCG.h"
#include "TitleText.h"
#include "Booper.h"
#include "SelectActor.h"

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
	CreateActor<Booper>(4);
	CreateActor<SelectActor>(5);
	SetCameraPos({ 680, 0 });

}

void TitleLevel::Update()
{
	MoveCameraPos(float4::LEFT * 0.2f);
	if (GetCameraPos().x <= 0.0f)
	{
		SetCameraPos({ 680,0 });
	}
	if (true == GameEngineInput::GetInst()->IsDown("Next"))
	{
		++TextPage_;
	}

}
