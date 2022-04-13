#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineRenderer;
class TitleText : public GameEngineActor
{
public:
	//construcuter destructer
	TitleText();
	~TitleText();

	//delete Function
	TitleText(const TitleText& _Other) = delete;
	TitleText(TitleText&& _Other) noexcept = delete;
	TitleText& operator=(const TitleText& _Other) = delete;
	TitleText& operator=(TitleText&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* MyRenderer_;

	void Start() override;
	void Update() override;
	void Render() override {};
};

