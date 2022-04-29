#include "GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GameEngineLevel.h"
#include "GameEngineImageManager.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngineBase/GameEngineSound.h>

std::map<std::string, GameEngineLevel*> GameEngine::AllLevel_;
GameEngineLevel* GameEngine::CurrentLevel_ = nullptr;
GameEngineLevel* GameEngine::NextLevel_ = nullptr;
GameEngineLevel* GameEngine::PrevLevel_ = nullptr;

GameEngine* GameEngine::UserContents_ = nullptr;
GameEngineImage* GameEngine::BackBufferImage_ = nullptr;
GameEngineImage* GameEngine::WindowMainImage_ = nullptr;

HDC GameEngine::BackBufferDC()
{
	return BackBufferImage_->ImageDC();
}

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::GameInit()
{
}

void GameEngine::GameLoop()
{
}

void GameEngine::GameEnd()
{
}

void GameEngine::WindowCreate()
{
	GameEngineWindow::GetInst().CreateGameWindow(nullptr, "GameWindow");
	GameEngineWindow::GetInst().ShowGameWindow();
	GameEngineWindow::GetInst().MessageLoop(EngineInit, EngineLoop);
}

void GameEngine::EngineInit()
{
	// 여기서 윈도우 크기가 결정되기 때문에
	UserContents_->GameInit();

	// 여기서 윈도우 크기만한 백버퍼 이미지를 만들어낸다.
	WindowMainImage_ = GameEngineImageManager::GetInst()->Create("WindowMain", GameEngineWindow::GetHDC());
	BackBufferImage_ = GameEngineImageManager::GetInst()->Create("BackBuffer", GameEngineWindow::GetScale());
}
void GameEngine::EngineLoop()
{
	// 컴퓨터 성능에 따라 게임 속도가 달라지지 않도록 시간을 이용해
	// 속도를 맞추기 위해 시간을 재는 함수
	GameEngineTime::GetInst()->Update();
	// 엔진 수준에서 매 프레임마다 체크하고 싶은 것을 넣는 부분
	UserContents_->GameLoop();

	if (nullptr != NextLevel_)
	{
		PrevLevel_ = CurrentLevel_;

		if (nullptr != CurrentLevel_)
		{
			// 레벨이 체인지 되기 전에 실행되는 함수
			CurrentLevel_->ActorLevelChangeEnd(NextLevel_);
			CurrentLevel_->LevelChangeEnd(NextLevel_);
			
			CurrentLevel_->ObjectLevelMoveCheck(NextLevel_);
		}
		GameEngineLevel* PrveLevel = CurrentLevel_;
		CurrentLevel_ = NextLevel_;

		if (nullptr != CurrentLevel_)
		{
			CurrentLevel_->LevelChangeStart(PrveLevel);
			CurrentLevel_->ActorLevelChangeStart(PrveLevel);
		}
		NextLevel_ = nullptr;
		GameEngineTime::GetInst()->Reset();

		Rectangle(WindowMainImage_->ImageDC(), 0, 0, WindowMainImage_->GetScale().ix(), WindowMainImage_->GetScale().iy());
		Rectangle(BackBufferImage_->ImageDC(), 0, 0, BackBufferImage_->GetScale().ix(), BackBufferImage_->GetScale().iy());
	}

	if (nullptr == CurrentLevel_)
	{
		MsgBoxAssert("Level is nullptr => GameEngine Loop ERROR");
	}

	GameEngineInput::GetInst()->Update(GameEngineTime::GetInst()->GetDeltaTime());

	// 레벨 수준에서 매 프레임마다 체크하는 일을 넣어놓는 함수
	
	CurrentLevel_->Update();
	CurrentLevel_->ActorUpdate();
	CurrentLevel_->ActorRender();
	CurrentLevel_->CollisionDebugRender();
	WindowMainImage_->BitCopy(BackBufferImage_);
	CurrentLevel_->ActorRelease();

	if (true == CurrentLevel_->IsReset)
	{
		CurrentLevel_->Reset();
		// 리셋이 되고나서 자신이 하고 싶은 일을 처리하는 함수
		CurrentLevel_->UserResetEnd();
		CurrentLevel_->IsReset = false;
	}
	
}

// 엔진이 종료하고 난 후 힙에 할당한 메모리를 삭제하는 함수
void GameEngine::EngineEnd()
{
	UserContents_->GameEnd();

	std::map<std::string, GameEngineLevel*>::iterator StartIter = AllLevel_.begin();
	std::map<std::string, GameEngineLevel*>::iterator EndIter = AllLevel_.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		if (nullptr == StartIter->second)
		{
			continue;
		}
		delete StartIter->second;
	}

	GameEngineSound::AllResourcesDestroy();
	GameEngineImageManager::Destory();
	GameEngineInput::Destroy();
	GameEngineTime::Destory();
	GameEngineWindow::Destory();
}

// 레벨을 바꾸는 함수
void GameEngine::ChangeLevel(const std::string& _Name)
{
	std::map<std::string, GameEngineLevel*>::iterator FindIter = AllLevel_.find(_Name);

	if (AllLevel_.end() == FindIter)
	{
		MsgBoxAssert("Level Find Error");
		return;
	}
	NextLevel_ = FindIter->second;
}