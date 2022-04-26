#pragma once
#include <GameEngine/GameEngineActor.h>

enum class PlayerState
{
	Idle,
	Move,
	Attack,
	Victory,
	Max,
};


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
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	void ChangeState(PlayerState _State);
	void StateUpdate();
	void CreateMoveEffect();
	void ChangeAnimation();

	bool IsMoveKey();
	void PlayerMove();
private:
	GameEngineRenderer* MyRenderer_;
	GameEngineImage* ColMapImage_;
	PlayerState CurState_;
	std::string dir_;
	std::string State_;
	float KeyCheckTime_;
	bool IsKeyOn_;


private:

	void IdleStart();
	void MoveStart();
	void AttackStart();
	void VictoryStart();

	void IdleUpdate();
	void MoveUpdate();
	void AttackUpdate();
	void VictoryUpdate();
};

