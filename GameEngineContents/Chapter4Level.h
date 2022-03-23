#pragma once
#include <GameEngine/GameEngineLevel.h>

class Chapter4Level : public GameEngineLevel
{
public:
	//construcuter destructer
	Chapter4Level();
	~Chapter4Level();

	//delete Function
	Chapter4Level(const Chapter4Level& _Other) = delete;
	Chapter4Level(Chapter4Level&& _Other) noexcept = delete;
	Chapter4Level& operator=(const Chapter4Level& _Other) = delete;
	Chapter4Level& operator=(Chapter4Level&& _Other) noexcept = delete;

protected:
	void Loading() override {};
	void Update() override {};

private:

};

