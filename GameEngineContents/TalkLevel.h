#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineSound.h>



class TalkLevel : public GameEngineLevel
{
public:
	static int TextPage_;


public:
	//construcuter destructer
	TalkLevel();
	~TalkLevel();

	//delete Function
	TalkLevel(const TalkLevel& _Other) = delete;
	TalkLevel(TalkLevel&& _Other) noexcept = delete;
	TalkLevel& operator=(const TalkLevel& _Other) = delete;
	TalkLevel& operator=(TalkLevel&& _Other) noexcept = delete;

protected:

private:
	void Loading() override;
	void Update() override;
	void LevelChangeStart() override;
	void LevelChangeEnd() override;

	GameEngineSoundPlayer TitleBgmPlayer_;
};

