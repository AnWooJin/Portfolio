#pragma once
#include <list>
#include <map>
#include <vector>
#include "GameEngineBase/GameEngineNameObject.h"
#include <GameEngineBase/GameEngineMath.h>

class GameEngine;
class GameEngineActor;
class GameEngineCollision;
class GameEngineRenderer;

class GameEngineActor;
struct ChangeOrderItem
{
	GameEngineActor* TargetObejct; // �� ���͸�
	int ChangeOrder; // �̷��� �ٲ��
};



class GameEngineLevel : public GameEngineNameObject
{
	friend GameEngine;
	friend GameEngineActor;
	friend GameEngineCollision;
	friend GameEngineRenderer;
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

	template<typename ActorType>
	ActorType* CreateActor(int _Order = 0, const std::string& _Name = "")
	{
		ActorType* NewActor = new ActorType();
		GameEngineActor* StartActor = NewActor;
		NewActor->SetOrder(_Order);
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

		return NewActor;
	}

	inline float4 GetCameraPos()
	{
		return CameraPos_;
	}

	inline void MoveCameraPos(const float4& _Value)
	{
		CameraPos_ += _Value;
	}

	inline void SetCameraPos(const float4& _Value)
	{
		CameraPos_ = _Value;
	}
protected:
	// ���ҽ��� �������ų� ���͸� ����� �Լ�
	virtual void Loading() = 0;
	// ���� �ؾ��ϴ� ���� �����ϴ� �Լ�
	virtual void Update() = 0;
	// CurrentLevel->NextLevel�� ��ȯ�� �� CurrentLevel�� �����ϴ� �Լ�
	virtual void LevelChangeStart() {}
	// CurrentLevel->NextLevel�� ��ȯ�� �� NextLevel�� �����ϴ� �Լ�
	virtual void LevelChangeEnd() {}
	
private:

	std::map<int, std::list<GameEngineActor*>>AllActor_;
	
	float4 CameraPos_;

	void ActorUpdate();
	void ActorRender();
	void CollisionDebugRender();
	void ActorRelease();

private:
	std::map<int, std::list<GameEngineRenderer*>> AllRenderer_;

	std::vector<ChangeOrderItem> ChangeOrderList;

	void AddRenderer(GameEngineRenderer* _Renderer);

	void ChangeUpdateOrder(GameEngineActor* _Actor, int _Order);

	void ChangeRenderOrder(GameEngineRenderer* _Renderer, int _NewOrder);

private:
	// ������ ���Ͱ� ������ ���� ����� Level
	// ���⼭�� GameEngineCollision*�� delete �ϸ� �ȵȴ�.
	std::map<std::string, std::list<GameEngineCollision*>> AllCollision_;

	void AddCollision(const std::string& _GroupName, GameEngineCollision* _Collision);
};

