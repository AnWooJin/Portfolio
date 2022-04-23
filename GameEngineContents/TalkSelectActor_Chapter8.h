#pragma once
#include <GameEngine/GameEngineActor.h>

enum class TalkSelectActor_Chapter8State
{
	Empty,
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

	bool GetIsSelect0()
	{
		return IsSelect0_;
	}

	bool GetIsSelect1()
	{
		return IsSelect1_;
	}
private:
	TalkSelectActor_Chapter8State CurState_;

	GameEngineRenderer* MyRenderer0_;
	GameEngineRenderer* MyRenderer1_;
	bool IsSelect0_;
	bool IsSelect1_;

	bool Selected0_;

	int SelectActorSetNum_;

	float ChangeTime_;

	void Start() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	void TalkSelectActorChange();
	void TalkSuccessCheck();
	void ChangeState(TalkSelectActor_Chapter8State _State);
	void StateUpdate();

	void EmptyStart();
	void BooperStart();
	void SelectActorStart();
	void SuccessStart();

	void EmptyUpdate();
	void BooperUpdate();
	void SelectActorUpdate();
	void SuccessUpdate();

	void Select0Check();
	void Select1Check();
	void Select0Setting();
	void Select1Setting();
};

