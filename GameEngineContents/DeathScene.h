#pragma once
#include <GameEngine/GameEngineActor.h>

enum class DeathSceneState
{
	Ani,
	Idle,
	Chapter6,
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
	int Chapter6Index_;
	GameEngineRenderer* MyRenderer_;
	DeathSceneState CurState_;

	void Start() override;
	void Update() override;
	void Render() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void ChangeState(DeathSceneState _State);
	void StateUpdate();

	void AniStart();
	void IdleStart();
	void Chapter6Start();
	void AniUpdate();
	void IdleUpdate();
	void Chapter6Update();


	///////// 챕터마다 다른 이미지를 렌더러에 넣어주는 함수
	void DeathSceneChange();
};

