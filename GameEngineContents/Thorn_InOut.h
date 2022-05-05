#pragma once
#include <GameEngine/GameEngineActor.h>

enum class Thorn_InOutState
{
	In,
	Out,
	Max,
};

class Player;
class GameEngineRenderer;
class gameEngineCollision;
class Thorn_InOut : public GameEngineActor
{
public:
	//construcuter destructer
	Thorn_InOut();
	~Thorn_InOut();

	//delete Function
	Thorn_InOut(const Thorn_InOut& _Other) = delete;
	Thorn_InOut(Thorn_InOut&& _Other) noexcept = delete;
	Thorn_InOut& operator=(const Thorn_InOut& _Other) = delete;
	Thorn_InOut& operator=(Thorn_InOut&& _Other) noexcept = delete;

public:
	void SetState(Thorn_InOutState _State);

protected:

private:
	void Start() override;
	void Render() override {};
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel);

	Player* MyPlayer_;
	GameEngineRenderer* MyRenderer_;
	GameEngineCollision* MyCollision_;
	Thorn_InOutState CurState_;

private:
	void ChangeState(Thorn_InOutState);
	void StateUpdate();

private:
	void InStart();
	void OutStart();
	void InUpdate();
	void OutUpdate();
};

