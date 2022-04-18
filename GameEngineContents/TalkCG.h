#pragma once
#include <GameEngine/GameEngineActor.h>

enum class TalkCGState
{
	Nomal,
	Success,
	Bad,
	Max,
};

class GameEngineRenderer;
class TalkCG : public GameEngineActor
{
public:
	//construcuter destructer
	TalkCG();
	~TalkCG();

	//delete Function
	TalkCG(const TalkCG& _Other) = delete;
	TalkCG(TalkCG&& _Other) noexcept = delete;
	TalkCG& operator=(const TalkCG& _Other) = delete;
	TalkCG& operator=(TalkCG&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* MyRenderer_;
	TalkCGState CurState_;

	void Start() override;
	void Update() override;

	void ChangeState(TalkCGState _State);
	void StateUpdate();
private:


	void NomalStart();
	void SuccessStart();

	void NomalUpdate();
	void SuccessUpdate();
};

