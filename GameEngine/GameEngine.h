#pragma once
#include <map>
#include <string>
#include <GameEngineBase/GameEngineDebug.h>

// ���ӿ����� ���� �� ��ü�� �������� ���� �������� ����Ѵ�.
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

	// ���� ������ �����찡 ��� ����� �� �ڼ��� �ڵ� ������ 
	// ���� ���ص� ������ �˸� ����� �� �ְ� �ϱ� ���� ������� �Լ�
	template<typename GameType>
	static void Start()
	{
		GameEngineDebug::LeakCheckOn();

		GameType UserGame;
		UserContents_ = &UserGame;

		WindowCreate();
		EngineEnd();
	}

	// �ٸ� Ŭ�������� ���� ���� ���ӿ����� �����ϱ� ���� �Լ�
	// ������ ����� �� ������ ������ ����Ǿ�� �ϱ� ������
	// ������� ���� �� ���α׷��� ������.
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

