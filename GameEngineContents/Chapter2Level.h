#pragma once
#include <GameEngine/GameEngineLevel.h>

class Chapter2Level : public GameEngineLevel
{
public:
	//construcuter destructer
	Chapter2Level();
	~Chapter2Level();

	//delete Function
	Chapter2Level(const Chapter2Level& _Other) = delete;
	Chapter2Level(Chapter2Level&& _Other) noexcept = delete;
	Chapter2Level& operator=(const Chapter2Level& _Other) = delete;
	Chapter2Level& operator=(Chapter2Level&& _Other) noexcept = delete;

protected:
	void Loading() override {};
	void Update() override {};

private:

};

