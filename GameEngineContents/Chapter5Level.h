#pragma once
#include <GameEngine/GameEngineLevel.h>

class Chapter5Level : public GameEngineLevel
{
public:
	//construcuter destructer
	Chapter5Level();
	~Chapter5Level();

	//delete Function
	Chapter5Level(const Chapter5Level& _Other) = delete;
	Chapter5Level(Chapter5Level&& _Other) noexcept = delete;
	Chapter5Level& operator=(const Chapter5Level& _Other) = delete;
	Chapter5Level& operator=(Chapter5Level&& _Other) noexcept = delete;

protected:
	void Loading() override {};
	void Update() override {};

private:

};

