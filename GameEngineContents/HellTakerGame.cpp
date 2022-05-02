#include "HellTakerGame.h"
#include "OpeningLevel.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "SceneChangeLevel.h"
#include "DeathLevel.h"
#include "TalkLevel.h"
#include "Talk_Chapter8Level.h"
#include "EndingLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineSound.h>

HellTakerGame::HellTakerGame()
	: ChapterCount_(1),
	  IsSuccess_(false)
{
}

HellTakerGame::~HellTakerGame()
{
}

void HellTakerGame::GameInit()
{
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100, 100 }, { 1280, 720 });
	GameSoundLoad();
	GameImageLoad();
	GameImageCut();
	FolderImageLoad();

	CreateLevel<OpeningLevel>("Opening");
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<TalkLevel>("Talk");
	CreateLevel<DeathLevel>("Death");
	CreateLevel<SceneChangeLevel>("SceneChange");
	CreateLevel<Talk_Chapter8Level>("Talk_Chapter8");
	CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Play");
}

void HellTakerGame::GameLoop()
{
	
}

void HellTakerGame::GameEnd()
{
}


void  HellTakerGame::GameSoundLoad()
{
	{

		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Portfolio");
		ResourcesDir.Move("Resource");
		ResourcesDir.Move("Sound");

		// 폴더안에 모든 이미지 파일을 찾는다.
		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile();

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineSound::LoadRes(AllImageFileList[i].GetFullPath());
		}

	}
}



void  HellTakerGame::GameImageLoad()
{
	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("Player");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}


	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("Map");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("BackGround");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("UI");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("SCG");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}


	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("Effect");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("Block");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("DevilSD");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("SceneChange");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("Scene");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}


	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("Enemy");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("etc");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("SelectActor");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("Text");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}


	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("DeathScene");
		std::vector<GameEngineFile> AllImageFileList = ResourceDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}
}

void HellTakerGame::GameImageCut()
{
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Chapter1Devil.bmp");
		Image->Cut({ 64, 64 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Chapter2_Devil.bmp");
		Image->Cut({ 64, 64 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Chapter3_Devil.bmp");
		Image->Cut({ 64, 64 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Chapter4_Devil.bmp");
		Image->Cut({ 64, 64 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Chapter5_Devil.bmp");
		Image->Cut({ 64, 64 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Chapter6_Devil.bmp");
		Image->Cut({ 64, 64 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Chapter7_Devil.bmp");
		Image->Cut({ 64, 64 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Chapter8_Devil.bmp");
		Image->Cut({ 64, 64 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Player_Idle_Right.bmp");
		Image->Cut({ 80, 80 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Player_Idle_Left.bmp");
		Image->Cut({ 80, 80 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Player_Move_Left.bmp");
		Image->Cut({ 64, 64 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Player_Move_Right.bmp");
		Image->Cut({ 64, 64 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Player_Kick_Right.bmp");
		Image->Cut({ 70, 72 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Player_Kick_Left.bmp");
		Image->Cut({ 70, 72 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Move_Right.bmp");
		Image->Cut({ 64, 64 });
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("HitEffect.bmp");
		Image->Cut({ 100, 100 });
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Player_Victory.bmp");
		Image->Cut({ 60, 82 });
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Player_Death.bmp");
		Image->Cut({ 250, 700 });
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Skull_Idle.bmp");
		Image->Cut({ 60,62 });
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Skull_Hit.bmp");
		Image->Cut({ 60,60 });
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Blocks_56.bmp");
		Image->Cut({ 56,60 });
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("LoveSign.bmp");
		Image->Cut({ 30,34 });
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Booper.bmp");
		Image->Cut({ 60,60 });
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Success.bmp");
		Image->Cut({ 740,134 });
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("TitleText.bmp");
		Image->Cut({ 1280,244 });
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Chapter8_TalkText_Idle.bmp");
		Image->Cut({ 1280,244 });
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("PrologueScene.bmp");
		Image->Cut({ 1280,720 });
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("DeathScene.bmp");
		Image->Cut({ 1080,330 });
	}


	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Chapter6_DeathScene.bmp");
		Image->Cut({ 1280,720 });
	}
}

void HellTakerGame::FolderImageLoad()
{
	{
		GameEngineDirectory ResourceDir;

		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("SceneChange");
		GameEngineImageManager::GetInst()->FolderImageLoad(ResourceDir.GetFullPath());
	}

	{
		GameEngineDirectory ResourceDir;
		ResourceDir.MoveParent("Portfolio");
		ResourceDir.Move("Resource");
		ResourceDir.Move("Image");
		ResourceDir.Move("TalkCG_Chapter8");
		GameEngineImageManager::GetInst()->FolderImageLoad(ResourceDir.GetFullPath());
	}
}