#pragma once
#include <GameEngine/GameEngineActor.h>
class MoveAni : public GameEngineActor
{
public:
	//construcuter destructer
	MoveAni();
	~MoveAni();

	//delete Function
	MoveAni(const MoveAni& _Other) = delete;
	MoveAni(MoveAni&& _Other) noexcept = delete;
	MoveAni& operator=(const MoveAni& _Other) = delete;
	MoveAni& operator=(MoveAni&& _Other) noexcept = delete;

protected:

private:
	void Start() override {};
	void Render() override {};
};

