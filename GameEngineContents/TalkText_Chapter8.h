#pragma once
#include <GameEngine/GameEngineActor.h>

enum class TalkText_Chapter8State
{
	Empty,
	Idle,
	Bad0,
	Bad1,
	Max,
};

class TalkText_Chapter8 : public GameEngineActor
{
public:
	//construcuter destructer
	TalkText_Chapter8();
	~TalkText_Chapter8();

	//delete Function
	TalkText_Chapter8(const TalkText_Chapter8& _Other) = delete;
	TalkText_Chapter8(TalkText_Chapter8&& _Other) noexcept = delete;
	TalkText_Chapter8& operator=(const TalkText_Chapter8& _Other) = delete;
	TalkText_Chapter8& operator=(TalkText_Chapter8&& _Other) noexcept = delete;

private:

	GameEngineRenderer* MyRenderer_;
	TalkText_Chapter8State CurState_;
	float ChangeTime_;

	void Start() override;
	void Update() override;
	void Render() override {};


	void ChangeState(TalkText_Chapter8State _State);
	void StateUpdate();
private:

	void EmptyStart();
	void IdleStart();
	void Bad0Start();
	void Bad1Start();

	void EmptyUpdate();
	void IdleUpdate();
	void Bad0Update();
	void Bad1Update();

};

