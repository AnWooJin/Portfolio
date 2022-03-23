#pragma once
#include <GameEngine/GameEngineActor.h>

class SkullBrokenAni : public GameEngineActor 
{
public:
	//construcuter destructer
	SkullBrokenAni();
	~SkullBrokenAni();

	//delete Function
	SkullBrokenAni(const SkullBrokenAni& _Other) = delete;
	SkullBrokenAni(SkullBrokenAni&& _Other) noexcept = delete;
	SkullBrokenAni& operator=(const SkullBrokenAni& _Other) = delete;
	SkullBrokenAni& operator=(SkullBrokenAni&& _Other) noexcept = delete;

protected:

private:
	void Start() override {};
	void Render() override {};
};

