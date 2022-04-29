#pragma once
#include "Player.h"
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineFont.h>

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
	Player* MyPlayer_;
	GameEngineFont TextFont;
	int Chapter_;

	void Start() override;
	void Update() override;
	void Render() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	void ChapterRender();
};

