#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <vector>

class GameEngineActor;
class Block;
class Skull;
class BackGroundMap;
class Player;
class DevilSD;
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
	
private:
	Player* MyPlayer_;
	BackGroundMap* MyMap_;
	DevilSD* MyDevil_;
	std::vector<Block*> Blocks_;
	std::vector<Skull*> Skulls_;

	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	void SkullSeting(int _ChapterLevel);
	void BlockSetting(int _ChapterLevel);

};

