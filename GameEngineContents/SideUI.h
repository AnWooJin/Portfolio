#pragma once
#include <GameEngine/GameEngineActor.h>

class SideUI : public GameEngineActor 
{
public:
	//construcuter destructer
	SideUI();
	~SideUI();

	//delete Function
	SideUI(const SideUI& _Other) = delete;
	SideUI(SideUI&& _Other) noexcept = delete;
	SideUI& operator=(const SideUI& _Other) = delete;
	SideUI& operator=(SideUI&& _Other) noexcept = delete;

protected:
	
private:
	void Start() override {};
	void Render() override {};
};

