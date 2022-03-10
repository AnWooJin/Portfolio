#pragma once
#include <GameEngine/GameEngineLevel.h>

class TalkLevel : public GameEngineLevel
{
public:
	//construcuter destructer
	TalkLevel();
	~TalkLevel();

	//delete Function
	TalkLevel(const TalkLevel& _Other) = delete;
	TalkLevel(TalkLevel&& _Other) noexcept = delete;
	TalkLevel& operator=(const TalkLevel& _Other) = delete;
	TalkLevel& operator=(TalkLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;

private:

};

