#pragma once
#include <GameEngine/GameEngineActor.h>

enum class TalkSelectActor_Chapter8State
{
	Booper,
	SelectActor,
	Success,
	Max,
};

class TalkSelectActor_Chapter8 : public GameEngineActor
{
public:
	//construcuter destructer
	TalkSelectActor_Chapter8();
	~TalkSelectActor_Chapter8();

	//delete Function
	TalkSelectActor_Chapter8(const TalkSelectActor_Chapter8& _Other) = delete;
	TalkSelectActor_Chapter8(TalkSelectActor_Chapter8&& _Other) noexcept = delete;
	TalkSelectActor_Chapter8& operator=(const TalkSelectActor_Chapter8& _Other) = delete;
	TalkSelectActor_Chapter8& operator=(TalkSelectActor_Chapter8&& _Other) noexcept = delete;

public:

	bool GetIsSelect()
	{
		return IsSelect_;
	}
private:
	TalkSelectActor_Chapter8State CurState_;

	GameEngineRenderer* MyRenderer0_;
	GameEngineRenderer* MyRenderer1_;
	bool Selected0_;
	bool IsSelect_;

	void Start() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	//void TalkSelectActorChange(int _Chapter);
	//void TalkSuccessCheck(int _Chapter);
	void ChangeState(TalkSelectActor_Chapter8State _State);
	void StateUpdate();


	void BooperStart();
	void SelectActorStart();
	void SuccessStart();

	void BooperUpdate();
	void SelectActorUpdate();
	void SuccessUpdate();
};

