#pragma once
#include <GameEngine/GameEngineActor.h>

class Sucesss : public GameEngineActor
{
public:
	//construcuter destructer
	Sucesss();
	~Sucesss();

	//delete Function
	Sucesss(const Sucesss& _Other) = delete;
	Sucesss(Sucesss&& _Other) noexcept = delete;
	Sucesss& operator=(const Sucesss& _Other) = delete;
	Sucesss& operator=(Sucesss&& _Other) noexcept = delete;

protected:

private:
	void Start() override {};
	void Render() override {};
};

