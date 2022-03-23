#pragma once
#include <GameEngine/GameEngineActor.h>

class Key : public GameEngineActor
{
public:
	//construcuter destructer
	Key();
	~Key();

	//delete Function
	Key(const Key& _Other) = delete;
	Key(Key&& _Other) noexcept = delete;
	Key& operator=(const Key& _Other) = delete;
	Key& operator=(Key&& _Other) noexcept = delete;

protected:

private:
	void Start();
	void Render();
};

