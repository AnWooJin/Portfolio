#pragma once
#include <GameEngine/GameEngineActor.h>


enum class TalkCGState
{
	Nomal,
	Success,
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
	int Chapter_;
	GameEngineRenderer* MyRenderer_;
	TalkCGState CurState_;

	void Start() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	void ChangeState(TalkCGState _State);
	void StateUpdate();
	void TalkCGSetting(int _Chapter);
private:


	void NomalStart();
	void SuccessStart();

	void NomalUpdate();
	void SuccessUpdate();

private:
	////////////////////////////  é�ͺ��� �̹����� �������ִ� �Լ�
	void Chapter1ImageSetting();
	void Chapter2ImageSetting();
	void Chapter3ImageSetting();
	void Chapter4ImageSetting();
	void Chapter5ImageSetting();
	void Chapter6ImageSetting();
};

