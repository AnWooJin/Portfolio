#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <vector>

class GameEngineActor;
class Block;
class Skull;
class PlayLevel : public GameEngineLevel
{
public:
	//construcuter destructer
	PlayLevel();
	~PlayLevel();

	//delete Function
	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator=(const PlayLevel& _Other) = delete;
	PlayLevel& operator=(PlayLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart() override;
private:
	int ChapterLevel_;
	GameEngineActor* MyPlayer_;
	std::vector<Block*> Blocks_;
	std::vector<Skull*> Skulls_;

	void SkullSeting(int _ChapterLevel);
	void BlockSetting(int _ChapterLevel);

};

