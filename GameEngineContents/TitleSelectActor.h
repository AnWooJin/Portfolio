#pragma once
#include <GameEngine/GameEngineActor.h>
enum class TitleSelectActorState
{
	Booper,
	SelectActor,
	Max,
};
class GameEngineRenderer;
class TitleSelectActor : public GameEngineActor
{
public:
	//construcuter destructer
	TitleSelectActor();
	~TitleSelectActor();

	//delete Function
	TitleSelectActor(const TitleSelectActor& _Other) = delete;
	TitleSelectActor(TitleSelectActor&& _Other) noexcept = delete;
	TitleSelectActor& operator=(const TitleSelectActor& _Other) = delete;
	TitleSelectActor& operator=(TitleSelectActor&& _Other) noexcept = delete;

protected:

private:
	TitleSelectActorState CurState_;

	GameEngineRenderer* MyRenderer0_;
	GameEngineRenderer* MyRenderer1_;

	bool IsSelected_;

	void Start() override;
	void Update() override;
	void Render() override {};
	void TitleImageChange();
	void ChangeState(TitleSelectActorState _State);
	void StateUpdate();


	void BooperStart();
	void SelectActorStart();

	void BooperUpdate();
	void SelectActorUpdate();
};

