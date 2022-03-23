#pragma once
#include <GameEngine/GameEngineActor.h>

class DeathAni : public GameEngineActor
{
public:
	//construcuter destructer
	DeathAni();
	~DeathAni();

	//delete Function
	DeathAni(const DeathAni& _Other) = delete;
	DeathAni(DeathAni&& _Other) noexcept = delete;
	DeathAni& operator=(const DeathAni& _Other) = delete;
	DeathAni& operator=(DeathAni&& _Other) noexcept = delete;

protected:

private:
	void Start() override {};
	void Render() override {};
};

