#pragma once
#include <GameEngine/GameEngineActor.h>

class Transition : public GameEngineActor
{
public:
	//construcuter destructer
	Transition();
	~Transition();

	//delete Function
	Transition(const Transition& _Other) = delete;
	Transition(Transition&& _Other) noexcept = delete;
	Transition& operator=(const Transition& _Other) = delete;
	Transition& operator=(Transition&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* MyRenderer_;

	void Start() override;
	void Update() override;
	void Render() override {};
};

