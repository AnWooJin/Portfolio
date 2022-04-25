#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineSound.h>

class Talk_Chapter8Level : public GameEngineLevel
{
public:
	//construcuter destructer
	Talk_Chapter8Level();
	~Talk_Chapter8Level();

	//delete Function
	Talk_Chapter8Level(const Talk_Chapter8Level& _Other) = delete;
	Talk_Chapter8Level(Talk_Chapter8Level&& _Other) noexcept = delete;
	Talk_Chapter8Level& operator=(const Talk_Chapter8Level& _Other) = delete;
	Talk_Chapter8Level& operator=(Talk_Chapter8Level&& _Other) noexcept = delete;

public:
	inline int GetTextPage()
	{
		return TextPage_;
	}

	void NextPage()
	{
		TextPage_ += 1;
	}

	inline void SelectActorCallOn()
	{
		SelectActorCall_ = true;
	}

	inline void SelectActorCallOff()
	{
		SelectActorCall_ = false;
		TextPage_ += 1;
	}

	bool GetSelectActorCall()
	{
		return SelectActorCall_;
	}



protected:


private:
	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;

	int TextPage_;
	GameEngineSoundPlayer TitleBgmPlayer_;
	bool SelectActorCall_;
};

