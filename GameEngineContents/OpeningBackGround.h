#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineRenderer;
class OpeningBackGround : public GameEngineActor
{
public:
	//construcuter destructer
	OpeningBackGround();
	~OpeningBackGround();

	//delete Function
	OpeningBackGround(const OpeningBackGround& _Other) = delete;
	OpeningBackGround(OpeningBackGround&& _Other) noexcept = delete;
	OpeningBackGround& operator=(const OpeningBackGround& _Other) = delete;
	OpeningBackGround& operator=(OpeningBackGround&& _Other) noexcept = delete;

private:
	GameEngineRenderer* OpeningBackGroundRenderer_;

	void Start() override;
	void Update() override;
	void Render() override {};
};

