#pragma once
#include <GameEngine/GameEngineActor.h>

enum class PlayerState
{
	Idle,
	Move,
	Attack,
	Victory,
	Death,
	Max,
};


class GameEngineImage;
class GameEngineCollision;
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

	bool GetHasKey()
	{
		return HasKey_;
	}

	int GetMoveCount()
	{
		return MoveCount_;
	}

	bool IsPlayerDeath()
	{
		return CurState_ == PlayerState::Death;
	}

	const float4 GetPlayerMovePos() const
	{
		return MovePos_;
	}

protected:

private:
	void Start() override;
	void Update() override;
	void Render() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	void ChangeState(PlayerState _State);
	void StateUpdate();
	void CreateMoveEffect();
	void CreateBloodEffect();
	void CreateHitEffect(float4 _Pos);
	void ChangeAnimation();

	bool IsMoveKey();
	void PlayerMove();
	void CameraCheck(float4 _Pos);
	void Chapter8CameraCheck(float4 _Pos);
private:
	GameEngineRenderer* MyRenderer_;
	GameEngineRenderer* BlackBackGround_;
	GameEngineCollision* MyCollision_;
	GameEngineImage* ColMapImage_;
	PlayerState CurState_;
	std::string dir_;
	std::string State_;
	float4 MovePos_;
	float KeyCheckTime_;
	float Time_;
	int MoveCount_;
	bool IsKeyOn_;
	bool HasKey_;


private:

	void IdleStart();
	void MoveStart();
	void AttackStart();
	void VictoryStart();
	void DeathStart();

	void IdleUpdate();
	void MoveUpdate();
	void AttackUpdate();
	void VictoryUpdate();
	void DeathUpdate();
};

