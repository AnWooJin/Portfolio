#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineImage;
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

public:
	void PlayerSetting(int _Chapter);

protected:

private:
	void Start() override;
	void Update() override;
	void Render() override;
	void KeyCheck();
	void CreateMoveEffect();
	bool IsMoveKey();
private:
	GameEngineRenderer* MyRender_;
	GameEngineRenderer* MyMoveRender_;
	GameEngineImage* ColMapImage_;
	float KeyCheckTime_;
	bool IsKeyOn_;
};

