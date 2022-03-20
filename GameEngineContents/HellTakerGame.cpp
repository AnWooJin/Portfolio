#include "HellTakerGame.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "TalkLevel.h"
#include "EndingLevel.h"
#include <GameEngineBase/GameEngineWindow.h>

HellTakerGame::HellTakerGame()
{
}

HellTakerGame::~HellTakerGame()
{
}

void HellTakerGame::GameInit()
{
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100, 100 }, { 1280, 720 });

	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Title");
}

void HellTakerGame::GameLoop()
{
}

void HellTakerGame::GameEnd()
{
}