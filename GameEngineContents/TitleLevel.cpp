#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleBackGround.h"
#include "TitleCG.h"
#include "TitleText.h"
#include "Booper.h"


TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Loading()
{
	CreateActor<TitleBackGround>(1);
	CreateActor<TitleCG>(2);
	CreateActor<TitleText>(3);
	CreateActor<Booper>(4);
	SetCameraPos({ 680, 0 });

}

void TitleLevel::Update()
{
	MoveCameraPos(float4::LEFT * 0.2f);
	if (GetCameraPos().x <= 0.0f)
	{
		SetCameraPos({ 680,0 });
	}
}
