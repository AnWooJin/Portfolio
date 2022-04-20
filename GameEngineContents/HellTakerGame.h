#pragma once
#include <GameEngine/GameEngine.h>

class HellTakerGame : public GameEngine
{
public:
	//construcuter destructer
	HellTakerGame();
	~HellTakerGame();

	//delete Function
	HellTakerGame(const HellTakerGame& _Other) = delete;
	HellTakerGame(HellTakerGame&& _Other) noexcept = delete;
	HellTakerGame& operator=(const HellTakerGame& _Other) = delete;
	HellTakerGame& operator=(HellTakerGame&& _Other) noexcept = delete;

	void GameInit() override;
	void GameLoop() override;
	void GameEnd() override;

public:
	inline bool GetIsSuccess() const
	{
		return IsSuccess_;
	}
	inline int GetChapterCount() const
	{
		return ChapterCount_;
	}
	inline void IsSuccesssOn()
	{
		IsSuccess_ = true;
	}
	inline void IsSuccesssOff()
	{
		IsSuccess_ = false;
	}
	inline void NextChapterCount()
	{
		++ChapterCount_;
	}

protected:

private:
	bool IsSuccess_;
	int ChapterCount_;
	void GameSoundLoad();
	void GameImageLoad();
	void GameImageCut();
	void FolderImageLoad();
};

