#pragma once
#include <GameEngine/GameEngineActor.h>

class Flame : public GameEngineActor
{
public:
	//construcuter destructer
	Flame();
	~Flame();

	//delete Function
	Flame(const Flame& _Other) = delete;
	Flame(Flame&& _Other) noexcept = delete;
	Flame& operator=(const Flame& _Other) = delete;
	Flame& operator=(Flame&& _Other) noexcept = delete;

protected:

private:
	void Start() override {};
	void Render() override {};
};

