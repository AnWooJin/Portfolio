#pragma once
#include <GameEngine/GameEngineLevel.h>

class PrologueLevel : public GameEngineLevel
{
public:
	//construcuter destructer
	PrologueLevel();
	~PrologueLevel();

	//delete Function
	PrologueLevel(const PrologueLevel& _Other) = delete;
	PrologueLevel(PrologueLevel&& _Other) noexcept = delete;
	PrologueLevel& operator=(const PrologueLevel& _Other) = delete;
	PrologueLevel& operator=(PrologueLevel&& _Other) noexcept = delete;

protected:
	
private:
	void Loading() override;
	void Update() override {};
	void LevelChangeEnd() override;
};

