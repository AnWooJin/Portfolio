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
	////////////////////////        ����� ��ġ�� �̹����� �����ִ� �Լ���
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
	///////////////////////          ���õ��� ��ġ�� ������Ʈ�� �� ������ �ٽ� ���ִ� �Լ���
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

