#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineRenderer;
class TalkBackGround_Chapter8 : public GameEngineActor
{
public:
	//construcuter destructer
	TalkBackGround_Chapter8();
	~TalkBackGround_Chapter8();

	//delete Function
	TalkBackGround_Chapter8(const TalkBackGround_Chapter8& _Other) = delete;
	TalkBackGround_Chapter8(TalkBackGround_Chapter8&& _Other) noexcept = delete;
	TalkBackGround_Chapter8& operator=(const TalkBackGround_Chapter8& _Other) = delete;
	TalkBackGround_Chapter8& operator=(TalkBackGround_Chapter8&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* BlackRenderer_;
	GameEngineRenderer* MyRenderer_;

	void Start() override;
	void Update() override;
	void Render() override {};
};

