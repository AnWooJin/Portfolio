#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <vector>

class GameEngineActor;
class Block;
class Skull;
class Chapter1Level : public GameEngineLevel
{
public:
	//construcuter destructer
	Chapter1Level();
	~Chapter1Level();

	//delete Function
	Chapter1Level(const Chapter1Level& _Other) = delete;
	Chapter1Level(Chapter1Level&& _Other) noexcept = delete;
	Chapter1Level& operator=(const Chapter1Level& _Other) = delete;
	Chapter1Level& operator=(Chapter1Level&& _Other) noexcept = delete;

protected:
	void Loading() override ;
	void Update() override ;
	void LevelChangeStart() override;

private:
	void SkullSeting();
	void BlockSetting();


private:
	GameEngineActor* MyPlayer_;
	std::vector<Block*> Blocks_;
	std::vector<Skull*> Skulls_;
};

