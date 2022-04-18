#pragma once
#include <GameEngine/GameEngineActor.h>
enum class TalkSelectActorState
{
	Booper,
	SelectActor,
	Max,
};
class GameEngineRenderer;
class TalkSelectActor : public GameEngineActor
{
public:
	//construcuter destructer
	TalkSelectActor();
	~TalkSelectActor();

	//delete Function
	TalkSelectActor(const TalkSelectActor& _Other) = delete;
	TalkSelectActor(TalkSelectActor&& _Other) noexcept = delete;
	TalkSelectActor& operator=(const TalkSelectActor& _Other) = delete;
	TalkSelectActor& operator=(TalkSelectActor&& _Other) noexcept = delete;

protected:

private:
	TalkSelectActorState CurState_;

	GameEngineRenderer* MyRenderer0_;
	GameEngineRenderer* MyRenderer1_;
	bool IsSelected_;

	void Start() override;
	void Update() override;

	void TitleImageChange();
	void ChangeState(TalkSelectActorState _State);
	void StateUpdate();


	void BooperStart();
	void SelectActorStart();

	void BooperUpdate();
	void SelectActorUpdate();
};

