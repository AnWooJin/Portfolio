#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRenderer.h>


class GameEngineRenderer;
class Player;
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
	void Update() override;
	void Render() override {};
	void LevelChangeStart(GameEngineLevel* PrevLevel) override;

	void SetColImage(int _Chapter);
	void BlockPush();
	void BlockMoveCheck(float4 _MovePos);
	void CreateMoveEffect();
	void CreateHitEffect();

	GameEngineCollision* MyCollision_;
	GameEngineImage* ColMapImage_;
	Player* MyPlayer_;
};

