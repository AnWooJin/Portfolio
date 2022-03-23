#pragma once
#include <GameEngine/GameEngineLevel.h>

class Chapter3Level : public GameEngineLevel
{
public:
	//construcuter destructer
	Chapter3Level();
	~Chapter3Level();

	//delete Function
	Chapter3Level(const Chapter3Level& _Other) = delete;
	Chapter3Level(Chapter3Level&& _Other) noexcept = delete;
	Chapter3Level& operator=(const Chapter3Level& _Other) = delete;
	Chapter3Level& operator=(Chapter3Level&& _Other) noexcept = delete;

protected:
	void Loading() override {};
	void Update() override {};

private:

};

