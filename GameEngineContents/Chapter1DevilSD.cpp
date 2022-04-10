#include "Chapter1DevilSD.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>

Chapter1DevilSD::Chapter1DevilSD()
{
}

Chapter1DevilSD::~Chapter1DevilSD()
{
}

void Chapter1DevilSD::Start()
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

void Chapter1DevilSD::Update()
{

}

void Chapter1DevilSD::Render()
{

}