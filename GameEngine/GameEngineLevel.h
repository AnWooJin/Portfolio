#pragma once
#include "GameEngineBase/GameEngineNameObject.h"
#include <list>
#include <map>

class GameEngine;
class GameEngineActor;
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

	template<typename ActorType>
	ActorType* CreateActor(int _Order = 0, const std::string& _Name = "")
	{
		ActorType* NewActor = new ActorType();
		GameEngineActor* StartActor = NewActor;
		NewActor->SetName(_Name);
		NewActor->SetLevel(this);
		StartActor->Start();
		std::list<GameEngineActor*>& Group = AllActor_[_Order];
		Group.push_back(NewActor);


		//// _Order 액터들이 돌아가는 순서를 의미하게 된다.
		//// insert와 find를 동시에 하게 됩니다.
		//std::map<int, std::list<GameEngineActor*>>::iterator FindGroup
		//	= AllActor_.find(_Order);

		//if (FindGroup == AllActor_.end())
		//{

		//	// AllActor_.insert(std::make_pair(_Order, std::list<GameEngineActor*>()));
		//	// 이게더 빠릅니다.
		//	AllActor_.insert(
		//		std::map<int, std::list<GameEngineActor*>>::value_type(_Order, std::list<GameEngineActor*>())
		//	);
		//	FindGroup = AllActor_.find(_Order);
		//}

		return NewActor;
	}
protected:
	// 리소스나 가져오거나 엑터를 만드는 함수
	virtual void Loading() = 0;
	// 현재 해야하는 일을 실행하는 함수
	virtual void Update() = 0;
	// CurrentLevel->NextLevel로 전환할 때 CurrentLevel이 실행하는 함수
	virtual void LevelChangeStart() {}
	// CurrentLevel->NextLevel로 전환할 때 NextLevel이 실행하는 함수
	virtual void LevelChangeEnd() {}
	
private:

	std::map<int, std::list<GameEngineActor*>>AllActor_;

	void ActorUpdate();
	void ActorRender();
	void ActorRelease();
};

