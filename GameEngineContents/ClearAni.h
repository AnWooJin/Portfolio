#pragma once
#include <GameEngine/GameEngineActor.h>

class ClearAni : public GameEngineActor
{
public:
	//construcuter destructer
	ClearAni();
	~ClearAni();

	//delete Function
	ClearAni(const ClearAni& _Other) = delete;
	ClearAni(ClearAni&& _Other) noexcept = delete;
	ClearAni& operator=(const ClearAni& _Other) = delete;
	ClearAni& operator=(ClearAni&& _Other) noexcept = delete;

protected:

private:
	void Start() override {};
	void Render() override {};
};

