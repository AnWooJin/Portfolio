#pragma once
#include <GameEngine/GameEngineActor.h>

enum class TalkTextState
{
	Nomal,
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


	void ChangeState(TalkTextState _State);
	void StateUpdate();
private:


	void NomalStart();
	void SuccessStart();
	void BadStart();

	void NomalUpdate();
	void SuccessUpdate();
	void BadUpdate();


	////////////////////////////////////  ���������� �´� �̹����� �������ִ� �Լ�
private:

	void ChapterNomalSetting();

};

