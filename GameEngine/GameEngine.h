#pragma once
#include <map>
#include <string>
#include <GameEngineBase/GameEngineDebug.h>

// 게임엔진은 게임 그 자체의 시작점과 끝점 실행중을 담당한다.
class GameEngineImage;
class GameEngineLevel;
class GameEngine
{
public:
	//construcuter destructer
	GameEngine();
	~GameEngine();

	//delete Function
	GameEngine(const GameEngine& _Other) = delete;
	GameEngine(GameEngine&& _Other) noexcept = delete;
	GameEngine& operator=(const GameEngine& _Other) = delete;
	GameEngine& operator=(GameEngine&& _Other) noexcept = delete;

	static inline GameEngineImage* BackBufferImage()
	{
		return BackBufferImage_;
	}

	static HDC BackBufferDC();

	virtual void GameInit() = 0;
	virtual void GameLoop() = 0;
	virtual void GameEnd() = 0;

	// 기존 유저가 윈도우가 어떻게 생기는 지 자세한 코드 내용을 
	// 알지 못해도 사용법만 알면 사용할 수 있게 하기 위해 만들어진 함수
	template<typename GameType>
	static void Start()
	{
		GameEngineDebug::LeakCheckOn();

		GameType UserGame;
		UserContents_ = &UserGame;

		WindowCreate();
		EngineEnd();
	}

	// 다른 클래스에서 내가 만든 게임엔진에 접근하기 위한 함수
	// 게임이 실행될 때 엔진도 무조건 실행되어야 하기 때문에
	// 실행되지 않을 시 프로그램이 터진다.
	static GameEngine& GetInst()
	{
		
		if (nullptr == UserContents_)
		{
			MsgBoxAssert("GEngine ERROR Engine is Not Start ");
		}

		return *UserContents_;
	}

	void ChangeLevel(const std::string& _Name);

	static inline GameEngineLevel* GetPrevLevel()
	{
		return PrevLevel_;
	}
protected:
	template<typename LevelType>
	void CreateLevel(const std::string& _Name)
	{
		LevelType* NewLevel = new LevelType();
		NewLevel->SetName(_Name);
		GameEngineLevel* Level = NewLevel;
		Level->Loading();
		AllLevel_.insert(std::make_pair(_Name, NewLevel));
	}

private:
	static std::map<std::string, GameEngineLevel*> AllLevel_;
	static GameEngineLevel* CurrentLevel_;
	static GameEngineLevel* NextLevel_;
	static GameEngineLevel* PrevLevel_;
	static GameEngine* UserContents_;

	static GameEngineImage* WindowMainImage_;
	static GameEngineImage* BackBufferImage_;


	static void WindowCreate();
	static void EngineInit();
	static void EngineLoop();
	static void EngineEnd();

};

