#pragma once
#include <GameEngine/GameEngineActor.h>
class Block : public GameEngineActor
{
public:
	//construcuter destructer
	Block();
	~Block();

	//delete Function
	Block(const Block& _Other) = delete;
	Block(Block&& _Other) noexcept = delete;
	Block& operator=(const Block& _Other) = delete;
	Block& operator=(Block&& _Other) noexcept = delete;


protected:


private:
	void Start() override {};
	void Render() override {};
};

