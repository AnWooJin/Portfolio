#pragma once
#include <GameEngine/GameEngineActor.h>

enum class TalkCGState_Chapter8
{
	Animation,
	Idle,
	Success0,
	Success1,
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
	bool VineSoundPlay_; 
	bool SkeletonSoundPlay_;


	void Start() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	void ChangeState(TalkCGState_Chapter8 _State);
	void StateUpdate();

private:
	void AnimationStart();
	void IdleStart();
	void Success0Start();
	void Success1Start();

	void AnimationUpdate();
	void IdleUpdate();
	void Success0Update();
	void Success1Update();

};

