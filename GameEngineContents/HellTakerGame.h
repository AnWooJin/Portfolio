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

protected:

private:
	void GameImageLoad();
	void GameImageCut();
};

