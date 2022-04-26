#pragma once
#include <GameEngine/GameEngineLevel.h>

class SceneChangeLevel : public GameEngineLevel
{
public:
	//construcuter destructer
	SceneChangeLevel();
	~SceneChangeLevel();

	//delete Function
	SceneChangeLevel(const SceneChangeLevel& _Other) = delete;
	SceneChangeLevel(SceneChangeLevel&& _Other) noexcept = delete;
	SceneChangeLevel& operator=(const SceneChangeLevel& _Other) = delete;
	SceneChangeLevel& operator=(SceneChangeLevel&& _Other) noexcept = delete;

protected:


private:
	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
};

