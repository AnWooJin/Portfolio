#pragma once
#include <GameEngine/GameEngineLevel.h>

class OpeningLevel : public GameEngineLevel
{
public:
	//construcuter destructer
	OpeningLevel();
	~OpeningLevel();

	//delete Function
	OpeningLevel(const OpeningLevel& _Other) = delete;
	OpeningLevel(OpeningLevel&& _Other) noexcept = delete;
	OpeningLevel& operator=(const OpeningLevel& _Other) = delete;
	OpeningLevel& operator=(OpeningLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;
};

