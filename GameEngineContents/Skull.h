#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRenderer.h>

class Player;
class Skull : public GameEngineActor
{
public:
	//construcuter destructer
	Skull();
	~Skull();

	//delete Function
	Skull(const Skull& _Other) = delete;
	Skull(Skull&& _Other) noexcept = delete;
	Skull& operator=(const Skull& _Other) = delete;
	Skull& operator=(Skull&& _Other) noexcept = delete;


protected:

private:
	void Start() override;
	void Update() override;
	void Render() override {};

	void SkullPush();

	void CreateMoveEffect();
	void CreateHitEffect();

private:
	GameEngineRenderer* MyRenderer_;
	GameEngineCollision* MyCollision_;
	Player* MyPlayer_;
};

