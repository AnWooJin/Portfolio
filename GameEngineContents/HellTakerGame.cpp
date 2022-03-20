#include "HellTakerGame.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "TalkLevel.h"
#include "EndingLevel.h"


HellTakerGame::HellTakerGame()
{
}

HellTakerGame::~HellTakerGame()
{
}

void HellTakerGame::GameInit()
{
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