#pragma once
#include <GameEngine/GameEngineLevel.h>

class Chapter7Level : public GameEngineLevel
{
public:
	//construcuter destructer
	Chapter7Level();
	~Chapter7Level();

	//delete Function
	Chapter7Level(const Chapter7Level& _Other) = delete;
	Chapter7Level(Chapter7Level&& _Other) noexcept = delete;
	Chapter7Level& operator=(const Chapter7Level& _Other) = delete;
	Chapter7Level& operator=(Chapter7Level&& _Other) noexcept = delete;

protected:
	void Loading() override {};
	void Update() override {};
private:

};

