#pragma once
#include <GameEngine/GameEngineLevel.h>

class EndingLevel : public GameEngineLevel
{
public:
	//construcuter destructer
	EndingLevel();
	~EndingLevel();

	//delete Function
	EndingLevel(const EndingLevel& _Other) = delete;
	EndingLevel(EndingLevel&& _Other) noexcept = delete;
	EndingLevel& operator=(const EndingLevel& _Other) = delete;
	EndingLevel& operator=(EndingLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;
private:

};

