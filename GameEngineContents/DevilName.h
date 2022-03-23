#pragma once
#include <GameEngine/GameEngineActor.h>

class DevilName : public GameEngineActor
{
public:
	//construcuter destructer
	DevilName();
	~DevilName();

	//delete Function
	DevilName(const DevilName& _Other) = delete;
	DevilName(DevilName&& _Other) noexcept = delete;
	DevilName& operator=(const DevilName& _Other) = delete;
	DevilName& operator=(DevilName&& _Other) noexcept = delete;

protected:

private:
	void Start() override {};
	void Render() override {};
};

