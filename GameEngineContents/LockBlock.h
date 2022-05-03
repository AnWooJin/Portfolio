#pragma once
#include <GameEngine/GameEngineActor.h>

class Player;
class GameEngineRenderer;
class LockBlock : public GameEngineActor
{
public:
	//construcuter destructer
	LockBlock();
	~LockBlock();

	//delete Function
	LockBlock(const LockBlock& _Other) = delete;
	LockBlock(LockBlock&& _Other) noexcept = delete;
	LockBlock& operator=(const LockBlock& _Other) = delete;
	LockBlock& operator=(LockBlock&& _Other) noexcept = delete;

protected:


private:

	void Start() override;
	void Update() override;
	void Render() override {};

	void KeyCheck();
	void CreateHugeEffect();

	GameEngineRenderer* MyRenderer_;
	GameEngineCollision* MyCollision_;
	Player* MyPlayer_;

};

