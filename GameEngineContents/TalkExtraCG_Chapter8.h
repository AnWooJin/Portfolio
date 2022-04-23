#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineMath.h>

class GameEngineRenderer;
class TalkExtraCG_Chapter8 : public GameEngineActor
{
public:
	//construcuter destructer
	TalkExtraCG_Chapter8();
	~TalkExtraCG_Chapter8();

	//delete Function
	TalkExtraCG_Chapter8(const TalkExtraCG_Chapter8& _Other) = delete;
	TalkExtraCG_Chapter8(TalkExtraCG_Chapter8&& _Other) noexcept = delete;
	TalkExtraCG_Chapter8& operator=(const TalkExtraCG_Chapter8& _Other) = delete;
	TalkExtraCG_Chapter8& operator=(TalkExtraCG_Chapter8&& _Other) noexcept = delete;

public:
	void SetMovePos(float4 _Pos)
	{
		MovePos_ = _Pos;
	}

protected:

private:
	void Start() override;
	void Update() override;
	void Render() override {};

	int Alpha_;
	float4 MovePos_;
	GameEngineRenderer* MyRenderer_;

};

