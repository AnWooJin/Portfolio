#pragma once
#include <GameEngine/GameEngineActor.h>

class LookBlock : public GameEngineActor
{
public:
	//construcuter destructer
	LookBlock();
	~LookBlock();

	//delete Function
	LookBlock(const LookBlock& _Other) = delete;
	LookBlock(LookBlock&& _Other) noexcept = delete;
	LookBlock& operator=(const LookBlock& _Other) = delete;
	LookBlock& operator=(LookBlock&& _Other) noexcept = delete;

protected:

private:
	void Start() override {};
	void Render() override {};
};

