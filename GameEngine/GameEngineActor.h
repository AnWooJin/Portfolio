#pragma once
#include <GameEngineBase/GameEngineNameObject.h>


class GameEngineActor
{
public:
	//construcuter destructer
	GameEngineActor();
	virtual ~GameEngineActor();

	//delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

protected:

private:

};

