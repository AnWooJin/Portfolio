#pragma once
#include <GameEngine/GameEngineActor.h>

class SelectActor : public GameEngineActor
{
public:
	//construcuter destructer
	SelectActor();
	~SelectActor();

	//delete Function
	SelectActor(const SelectActor& _Other) = delete;
	SelectActor(SelectActor&& _Other) noexcept = delete;
	SelectActor& operator=(const SelectActor& _Other) = delete;
	SelectActor& operator=(SelectActor&& _Other) noexcept = delete;

protected:

private:
	void Start() override {};
	void Render() override {};
};

