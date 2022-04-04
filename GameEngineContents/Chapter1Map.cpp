#include "Chapter1Map.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>


Chapter1Map::Chapter1Map()
{
}

Chapter1Map::~Chapter1Map()
{
}

void Chapter1Map::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	CreateRenderer("chapterBG01.bmp");
	CreateRenderer("SideUI.bmp");
}

void Chapter1Map::Render()
{

}