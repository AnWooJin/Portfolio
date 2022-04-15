#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineSound.h>

class TitleLevel : public GameEngineLevel
{
public:
	static int TextPage_;

	//construcuter destructer
	TitleLevel();
	~TitleLevel();

	//delete Function
	TitleLevel(const TitleLevel& _Other) = delete;
	TitleLevel(TitleLevel&& _Other) noexcept = delete;
	TitleLevel& operator=(const TitleLevel& _Other) = delete;
	TitleLevel& operator=(TitleLevel&& _Other) noexcept = delete;

	GameEngineSoundPlayer MyBgmPlayer_;

protected:
	
private:
	void Loading() override;
	void Update() override;
	void LevelChangeStart() override;
	void LevelChangeEnd() override;
	
};

