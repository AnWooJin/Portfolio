#include "HellTakerGame.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "EndingLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngine/GameEngineImageManager.h>

HellTakerGame::HellTakerGame()
{
}

HellTakerGame::~HellTakerGame()
{
}

void HellTakerGame::GameInit()
{
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100, 100 }, { 1280, 720 });

	GameEngineDirectory ResourceDir;
	
	ResourceDir.MoveParent("Portfolio");
	ResourceDir.Move("Resource");
	
	std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}

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