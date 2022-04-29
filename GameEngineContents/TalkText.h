#pragma once
#include <GameEngine/GameEngineActor.h>

enum class TalkTextState
{
	Idle,
	Success,
	Bad,
	Max,
};

class GameEngineRenderer;
class TalkText : public GameEngineActor
{
public:
	//construcuter destructer
	TalkText();
	~TalkText();

	//delete Function
	TalkText(const TalkText& _Other) = delete;
	TalkText(TalkText&& _Other) noexcept = delete;
	TalkText& operator=(const TalkText& _Other) = delete;
	TalkText& operator=(TalkText&& _Other) noexcept = delete;

protected:


private:
	
	GameEngineRenderer* MyRenderer_;
	TalkTextState CurState_;

	void Start() override;
	void Update() override;
	void Render() override {};
	void LevelChangeStart(GameEngineLevel* PrevLevel) override;

	void ChangeState(TalkTextState _State);
	void StateUpdate();
private:


	void IdleStart();
	void SuccessStart();
	void BadStart();

	void IdleUpdate();
	void SuccessUpdate();
	void BadUpdate();


	////////////////////////////////////  ���������� �´� �̹����� �������ִ� �Լ�
private:

	void ChapterTextSetting();

	void Chapter1TextSetting();
	void Chapter2TextSetting();
	void Chapter3TextSetting();
	void Chapter4TextSetting();
	void Chapter5TextSetting();
	void Chapter6TextSetting();
	void Chapter7TextSetting();
};

