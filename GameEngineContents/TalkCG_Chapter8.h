#pragma once
#include <GameEngine/GameEngineActor.h>

enum class TalkCGState_Chapter8
{
	Idle,
	Success,
	Max,
};

class GameEngineRenderer;
class TalkCG_Chapter8 : public GameEngineActor
{
public:
	//construcuter destructer
	TalkCG_Chapter8();
	~TalkCG_Chapter8();

	//delete Function
	TalkCG_Chapter8(const TalkCG_Chapter8& _Other) = delete;
	TalkCG_Chapter8(TalkCG_Chapter8&& _Other) noexcept = delete;
	TalkCG_Chapter8& operator=(const TalkCG_Chapter8& _Other) = delete;
	TalkCG_Chapter8& operator=(TalkCG_Chapter8&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* MyRenderer_;
	TalkCGState_Chapter8 CurState_;
	bool IsCreateExtraActor_;


	void Start() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void CreateExtraActor0();
	void CreateExtraActor1();

	void ChangeState(TalkCGState_Chapter8 _State);
	void StateUpdate();

private:
	void IdleStart();
	void SuccessStart();

	void IdleUpdate();
	void SuccessUpdate();

};

