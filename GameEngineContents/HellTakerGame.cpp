#include "HellTakerGame.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "Chapter1Level.h"
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
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Chapter1Devil.bmp");
		Image->Cut({ 64, 64 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Player_Right.bmp");
		Image->Cut({ 80, 80 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Player_Left.bmp");
		Image->Cut({ 80, 80 });
	}

	

	CreateLevel<TitleLevel>("Title");
	CreateLevel<Chapter1Level>("Chapter1Level");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Chapter1Level");
}

void HellTakerGame::GameLoop()
{
}

void HellTakerGame::GameEnd()
{
}