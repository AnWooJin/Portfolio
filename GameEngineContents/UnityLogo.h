#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineRenderer;
class UnityLogo : public GameEngineActor
{
public:
	//construcuter destructer
	UnityLogo();
	~UnityLogo();

	//delete Function
	UnityLogo(const UnityLogo& _Other) = delete;
	UnityLogo(UnityLogo&& _Other) noexcept = delete;
	UnityLogo& operator=(const UnityLogo& _Other) = delete;
	UnityLogo& operator=(UnityLogo&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* UnityRenderer_;
	unsigned int Alpha_;
	float AlphaTime_;

	void Start() override;
	void Update() override;
	void Render() override {};
};

