#pragma once
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngine/GameEngineLevel.h>
#include <vector>


enum class PlayOrder
{
	BackGround,
	UI,
	Thorn,
	Block,
	SKull,
	Devil,
	Player,
};


class GameEngineActor;
class LockBlock;
class Block;
class Skull;
class BackGroundMap;
class Player;
class Key;
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
	bool IsBgmPlay_;
	Player* MyPlayer_;
	Key* MyKey_;
	BackGroundMap* MyMap_;
	DevilSD* MyDevil_;
	std::vector<Block*> Blocks_;
	std::vector<Skull*> Skulls_;
	LockBlock* LockBlock_;
	GameEngineSoundPlayer PlayBgmPlayer_;

	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;
	

	void ActorOff();                ////  ������ ������Ʈ�� �Ͻ������� ���ϰ� ����� �Լ�
	void SkullSetting();
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

private:
	void Thorn_Chapter1Set();
	void Thorn_Chapter2Set();
	void Thorn_Chapter3Set();
	void Thorn_Chapter4Set();
	void Thorn_Chapter5Set();
	void Thorn_Chapter6Set();
	void Thorn_Chapter7Set();
	void Thorn_Chapter8Set();
	void Thorn_Chapter9Set();



};

