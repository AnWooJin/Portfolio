#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineRenderer;
class TalkBackGround : public GameEngineActor
{
public:
	//construcuter destructer
	TalkBackGround();
	~TalkBackGround();

	//delete Function
	TalkBackGround(const TalkBackGround& _Other) = delete;
	TalkBackGround(TalkBackGround&& _Other) noexcept = delete;
	TalkBackGround& operator=(const TalkBackGround& _Other) = delete;
	TalkBackGround& operator=(TalkBackGround&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* BlackRenderer_;
	GameEngineRenderer* MyRenderer_;

	void Start() override;
	void Update() override;
	void Render() override {};

};

