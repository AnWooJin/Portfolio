#pragma once
#include <GameEngine/GameEngineLevel.h>

class Chapter1Level : public GameEngineLevel
{
public:
	//construcuter destructer
	Chapter1Level();
	~Chapter1Level();

	//delete Function
	Chapter1Level(const Chapter1Level& _Other) = delete;
	Chapter1Level(Chapter1Level&& _Other) noexcept = delete;
	Chapter1Level& operator=(const Chapter1Level& _Other) = delete;
	Chapter1Level& operator=(Chapter1Level&& _Other) noexcept = delete;

protected:
	void Loading() override {};
	void Update() override {};

private:

};

