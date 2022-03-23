#pragma once
#include <GameEngine/GameEngineLevel.h>

class Chapter9Level : public GameEngineLevel
{
public:
	//construcuter destructer
	Chapter9Level();
	~Chapter9Level();

	//delete Function
	Chapter9Level(const Chapter9Level& _Other) = delete;
	Chapter9Level(Chapter9Level&& _Other) noexcept = delete;
	Chapter9Level& operator=(const Chapter9Level& _Other) = delete;
	Chapter9Level& operator=(Chapter9Level&& _Other) noexcept = delete;

protected:
	void Loading() override {};
	void Update() override {};

private:

};

