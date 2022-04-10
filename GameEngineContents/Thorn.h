#pragma once
#include <GameEngine/GameEngineActor.h>

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
	void Render() override {};
};

