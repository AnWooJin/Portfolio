#pragma once
#include <GameEngine/GameEngineLevel.h>

class Chapter8Level : public GameEngineLevel
{
public:
	//construcuter destructer
	Chapter8Level();
	~Chapter8Level();

	//delete Function
	Chapter8Level(const Chapter8Level& _Other) = delete;
	Chapter8Level(Chapter8Level&& _Other) noexcept = delete;
	Chapter8Level& operator=(const Chapter8Level& _Other) = delete;
	Chapter8Level& operator=(Chapter8Level&& _Other) noexcept = delete;

protected:

private:

};

