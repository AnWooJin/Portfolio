#pragma once
#include "GameEngineBase/GameEngineNameObject.h"

class GameEngine;
class GameEngineLevel : public GameEngineNameObject
{
	friend GameEngine;
public:
	//construcuter destructer
	GameEngineLevel();

	// virtual을 붙이는 이유
	// 업케스팅으로 객체를 생성할 경우 자식의 소멸자가 자동으로 호출되지 않기 때문에
	// virtual을 붙여주어서 자식의 소멸자도 호출하게 만들어야 한다.
	virtual ~GameEngineLevel();

	//delete Function
	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

protected:
	virtual void Loading() = 0;

	// 레벨 수준의 업데이트
	virtual void Update() = 0;

private:
	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name)
	{
		return nullptr;
	}
};

