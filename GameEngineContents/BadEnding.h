#pragma once
#include <GameEngine/GameEngineActor.h>

class BadEnding : public GameEngineActor
{
public:
	//construcuter destructer
	BadEnding();
	~BadEnding();

	//delete Function
	BadEnding(const BadEnding& _Other) = delete;
	BadEnding(BadEnding&& _Other) noexcept = delete;
	BadEnding& operator=(const BadEnding& _Other) = delete;
	BadEnding& operator=(BadEnding&& _Other) noexcept = delete;

protected:

private:
	void Start() override {};
	void Render() override {};
};

