#pragma once
#include <GameEngine/GameEngineActor.h>

class Skull : public GameEngineActor
{
public:
	//construcuter destructer
	Skull();
	~Skull();

	//delete Function
	Skull(const Skull& _Other) = delete;
	Skull(Skull&& _Other) noexcept = delete;
	Skull& operator=(const Skull& _Other) = delete;
	Skull& operator=(Skull&& _Other) noexcept = delete;

protected:

private:
	void Start() override {};
	void Render() override {};
};

