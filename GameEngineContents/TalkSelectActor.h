#pragma once
#include <GameEngine/GameEngineActor.h>
enum class TalkSelectActorState
{
	Booper,
	SelectActor,
	Success,
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
	void SuccessStart();

	void BooperUpdate();
	void SelectActorUpdate();
	void SuccessUpdate();

private:
	////////////////////// 챕터별로 셀렉트 이미지를 정해주는 함수
	void Chapter1Setting();
	void Chapter2Setting();
	void Chapter3Setting();
	void Chapter4Setting();
	void Chapter5Setting();
	void Chapter6Setting();
	void Chapter7Setting();
private:
	/////////////////////// 챕터별로 성공여부를 판단하는 함수
	void Chapter1Check();
	void Chapter2Check();
	void Chapter3Check();
	void Chapter4Check();
	void Chapter5Check();
	void Chapter6Check();
	void Chapter7Check();
};

