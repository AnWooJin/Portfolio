#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineCollision;
class Thorn : public GameEngineActor	
{
public:
	//construcuter destructer
	Thorn();
	~Thorn();

	//delete Function
	Thorn(const Thorn& _Other) = delete;
	Thorn(Thorn&& _Other) noexcept = delete;
	Thorn& operator=(const Thorn& _Other) = delete;
	Thorn& operator=(Thorn&& _Other) noexcept = delete;

protected:

private:
	void Start() override;
	void Update() override;
	void Render() override {};
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;

	GameEngineCollision* MyCollision_;
};

