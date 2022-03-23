#pragma once
#include <GameEngine/GameEngineLevel.h>

class Chapter6Level : public GameEngineLevel
{
public:
	//construcuter destructer
	Chapter6Level();
	~Chapter6Level();

	//delete Function
	Chapter6Level(const Chapter6Level& _Other) = delete;
	Chapter6Level(Chapter6Level&& _Other) noexcept = delete;
	Chapter6Level& operator=(const Chapter6Level& _Other) = delete;
	Chapter6Level& operator=(Chapter6Level&& _Other) noexcept = delete;

protected:
	void Loading() override {};
	void Update() override {};

private:

};

