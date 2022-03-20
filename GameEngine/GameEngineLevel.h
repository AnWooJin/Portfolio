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

	// virtual�� ���̴� ����
	// ���ɽ������� ��ü�� ������ ��� �ڽ��� �Ҹ��ڰ� �ڵ����� ȣ����� �ʱ� ������
	// virtual�� �ٿ��־ �ڽ��� �Ҹ��ڵ� ȣ���ϰ� ������ �Ѵ�.
	virtual ~GameEngineLevel();

	//delete Function
	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

protected:
	// ���ҽ��� �������ų� ���͸� ����� �Լ�
	virtual void Loading() = 0;
	// ���� �ؾ��ϴ� ���� �����ϴ� �Լ�
	virtual void Update() = 0;
	// CurrentLevel->NextLevel�� ��ȯ�� �� CurrentLevel�� �����ϴ� �Լ�
	virtual void LevelChangeStart() {}
	// CurrentLevel->NextLevel�� ��ȯ�� �� NextLevel�� �����ϴ� �Լ�
	virtual void LevelChangeEnd() {}
	
	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name, int _Order)
	{
		ActorType* NewActor = new ActorType();
		GameEngineActor* StartActor = NewActor;
		NewActor->SetName(_Name);

		NewActor->SetLevel(this);
		StartActor->Start();
		std::list<GameEngineActor*>& Group = AllActor_[_Order];
		Group.push_back(NewActor);


		//// _Order ���͵��� ���ư��� ������ �ǹ��ϰ� �ȴ�.
		//// insert�� find�� ���ÿ� �ϰ� �˴ϴ�.
		//std::map<int, std::list<GameEngineActor*>>::iterator FindGroup
		//	= AllActor_.find(_Order);

		//if (FindGroup == AllActor_.end())
		//{

		//	// AllActor_.insert(std::make_pair(_Order, std::list<GameEngineActor*>()));
		//	// �̰Դ� �����ϴ�.
		//	AllActor_.insert(
		//		std::map<int, std::list<GameEngineActor*>>::value_type(_Order, std::list<GameEngineActor*>())
		//	);
		//	FindGroup = AllActor_.find(_Order);
		//}

		return nullptr;
	}
private:

	std::map<int, std::list<GameEngineActor*>>AllActor_;

	void ActorUpdate();
	void ActorRender();
};

