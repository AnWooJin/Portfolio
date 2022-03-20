#include "GameEngineActor.h"
#include <GameEngineBase/GameEngineWindow.h>

GameEngineActor::GameEngineActor()
	: Level_(nullptr)
	, Position_({0.0f,})
	, Scale_({0.0f,})
{
}

GameEngineActor::~GameEngineActor()
{
}

void GameEngineActor::DebugRectRender()
{
	GameEngineRect DebugRect(Position_, Scale_);

	for (size_t i = 0; i < 100; i++)
	{
		SetPixel(GameEngineWindow::GetHDC(), 100 + i, 100, RGB(255, 0, 0));
	}
}