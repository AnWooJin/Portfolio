#pragma once
#include <GameEngine/GameEngineActor.h>
enum class TalkSelectActorState
{
	Booper,
	SelectActor,
	Max,
};
class GameEngineRenderer;
class TalkSelectActor : public GameEngineActor
{

public:

	bool GetIsSelect()
	{
		return IsSelect_;
	}

public:
	//construcuter destructer
	TalkSelectActor();
	~TalkSelectActor();

	//delete Function
	TalkSelectActor(const TalkSelectActor& _Other) = delete;
	TalkSelectActor(TalkSelectActor&& _Other) noexcept = delete;
	TalkSelectActor& operator=(const TalkSelectActor& _Other) = delete;
	TalkSelectActor& operator=(TalkSelectActor&& _Other) noexcept = delete;

protected:

private:
	TalkSelectActorState CurState_;

	GameEngineRenderer* MyRenderer0_;
	GameEngineRenderer* MyRenderer1_;
	bool Selected0_;
	bool IsSelect_;
	int Chapter_;

	void Start() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	void TalkSelectActorChange(int _Chapter);
	void TalkSuccessCheck(int _Chapter);
	void ChangeState(TalkSelectActorState _State);
	void StateUpdate();


	void BooperStart();
	void SelectActorStart();

	void BooperUpdate();
	void SelectActorUpdate();

private:
	////////////////////// é�ͺ��� ����Ʈ �̹����� �����ִ� �Լ�
	void Chapter1Setting();



private:
	/////////////////////// é�ͺ��� �������θ� �Ǵ��ϴ� �Լ�
	void Chapter1Check();
};

