#pragma once
#include <GameEngine/GameEngineActor.h>
class GameEngineRenderer;
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

	void  GetRender() {};
	GameEngineRenderer* BlockRender_;

protected:


private:
	void Start() override;
	void Update() override {};
	void Render() override {};

};

