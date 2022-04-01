#pragma once
#include <GameEngine/GameEngineActor.h>

class Player : public GameEngineActor
{
public:
	//construcuter destructer
	Player();
	~Player();

	//delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

protected:

private:
	void Start() override;
	void Update() override;
	void Render() override;
	void KeyCheck();

private:
	GameEngineRenderer* MyRender_;
	GameEngineRenderer* MyMoveRender_;
	float KeyCheckTime_;
	bool IsKeyOn_;
};

