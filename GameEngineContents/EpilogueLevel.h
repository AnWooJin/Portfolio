#pragma once
#include <GameEngine/GameEngineLevel.h>

class EpilogueLevel : public GameEngineLevel
{
public:
	//construcuter destructer
	EpilogueLevel();
	~EpilogueLevel();

	//delete Function
	EpilogueLevel(const EpilogueLevel& _Other) = delete;
	EpilogueLevel(EpilogueLevel&& _Other) noexcept = delete;
	EpilogueLevel& operator=(const EpilogueLevel& _Other) = delete;
	EpilogueLevel& operator=(EpilogueLevel&& _Other) noexcept = delete;

protected:

private:
	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

};

