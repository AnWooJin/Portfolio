#pragma once
#include <GameEngine/GameEngineLevel.h>

class DeathLevel : public GameEngineLevel
{
public:
	//construcuter destructer
	DeathLevel();
	~DeathLevel();

	//delete Function
	DeathLevel(const DeathLevel& _Other) = delete;
	DeathLevel(DeathLevel&& _Other) noexcept = delete;
	DeathLevel& operator=(const DeathLevel& _Other) = delete;
	DeathLevel& operator=(DeathLevel&& _Other) noexcept = delete;

protected:


private:
	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
};

