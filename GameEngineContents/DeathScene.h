#pragma once
#include <GameEngine/GameEngineActor.h>

enum class DeathSceneState
{
	Ani,
	Idle,
	Max,
};


class GameEngineRenderer;
class DeathScene : public GameEngineActor
{
public:
	//construcuter destructer
	DeathScene();
	~DeathScene();

	//delete Function
	DeathScene(const DeathScene& _Other) = delete;
	DeathScene(DeathScene&& _Other) noexcept = delete;
	DeathScene& operator=(const DeathScene& _Other) = delete;
	DeathScene& operator=(DeathScene&& _Other) noexcept = delete;

protected:


private:
	int Chapter_;
	GameEngineRenderer* MyRenderer_;
	DeathSceneState CurState_;

	void Start() override;
	void Update() override;
	void Render() override;

	void ChangeState(DeathSceneState _State);
	void StateUpdate();

	void AniStart();
	void IdleStart();
	void AniUpdate();
	void IdleUpdate();
};

