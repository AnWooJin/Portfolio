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
	int Chapter_;
	Player* MyPlayer_;
	BackGroundMap* MyMap_;
	DevilSD* MyDevil_;
	std::vector<Block*> Blocks_;
	std::vector<Skull*> Skulls_;

	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;
	void ActorsReset();
	void ActorsCreate();

	void SkullSeting();
	void BlockSetting();
	void ThornSetting();


private:
	////////////////////////        블록의 위치와 이미지를 정해주는 함수들
	void Block_Chapter1Set();
	void Block_Chapter2Set();
	void Block_Chapter3Set();
	void Block_Chapter4Set();
	void Block_Chapter5Set();
	void Block_Chapter6Set();
	void Block_Chapter7Set();
	void Block_Chapter8Set();
	void Block_Chapter9Set();
private:
	///////////////////////          스컬들의 위치와 업데이트를 끈 스컬을 다시 켜주는 함수들
	void SKull_Chapter1Set();
	void SKull_Chapter2Set();
	void SKull_Chapter3Set();
	void SKull_Chapter4Set();
	void SKull_Chapter5Set();
	void SKull_Chapter6Set();
	void SKull_Chapter7Set();
	void SKull_Chapter8Set();
	void SKull_Chapter9Set();


};

