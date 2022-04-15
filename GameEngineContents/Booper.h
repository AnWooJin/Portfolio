#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineRenderer;
class Booper : public GameEngineActor
{
public:
	//construcuter destructer
	Booper();
	~Booper();

	//delete Function
	Booper(const Booper& _Other) = delete;
	Booper(Booper&& _Other) noexcept = delete;
	Booper& operator=(const Booper& _Other) = delete;
	Booper& operator=(Booper&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* MyRenderer_;

	void Start() override;
	void Update() override;
	void Render() override {};

};

