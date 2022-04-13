#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineRenderer;
class TitleBackGround : public GameEngineActor
{
public:
	//construcuter destructer
	TitleBackGround();
	~TitleBackGround();

	//delete Function
	TitleBackGround(const TitleBackGround& _Other) = delete;
	TitleBackGround(TitleBackGround&& _Other) noexcept = delete;
	TitleBackGround& operator=(const TitleBackGround& _Other) = delete;
	TitleBackGround& operator=(TitleBackGround&& _Other) noexcept = delete;

protected:
	void Start() override;

	void Render() override;

private:
	GameEngineRenderer* MyRenderer_;
};

