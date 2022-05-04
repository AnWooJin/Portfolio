#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRenderer.h>


enum class SkullState
{
	Idle,
	Hit,
	Max,
};

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
	void LevelChangeStart(GameEngineLevel* PrevLevel) override;

	void SkullPush();
	void SkullDeathCheck(float4 _MovePos);
	void SetColImage(int _Chapter);

	void CreateMoveEffect();
	void CreateHitEffect();


private:
	void ChangeState(SkullState _State);
	void StateUpdate();

private:
	void IdleStart();
	void HitStart();
	void IdleUpdate();
	void HitUpdate();

private:
	GameEngineRenderer* MyRenderer_;
	GameEngineCollision* MyCollision_;
	GameEngineImage* ColMapImage_;
	SkullState CurState_;
	Player* MyPlayer_;
	float4 StartPos_;
	float4 EndPos_;
	float Time_;
};

