#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineUpdateObject.h>
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineEnum.h"
#include <list>

class GameEngineRenderer;
class GameEngineLevel;
class GameEngineActor : public GameEngineNameObject, public GameEngineUpdateObject
{
// Actor�� �⺻������ ������ �ϴ� ��ɵ�
public:
	friend GameEngineLevel;

	//construcuter destructer
	GameEngineActor();
	virtual ~GameEngineActor();

	//delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

	inline GameEngineLevel* GetLevel()
	{
		return Level_;
	}

	inline float4 GetPosition()
	{
		return Position_;
	}

	inline float4 GetScale()
	{
		return Scale_;
	}

	inline void SetMove(const float4& _Value)
	{
		Position_ += _Value;
	}
	inline void SetPosition(float4 _Value)
	{
		Position_ = _Value;
	}

	inline void SetScale(float4 _Value)
	{
		Scale_ = _Value;
	}

protected:
	// ������ �� ������ �ϰ� ������ �����ڿ����� ���� ���ϴ� �κ��� ����ϴ� �Լ�
	virtual void Start() = 0;
	// ���������� ������ ����� �� ȣ��Ǵ� �Լ�
	virtual void Update() {}
	// ���������� ������ ����� �� ������ �̹����� �׸��� �Լ�
	virtual void Render() {}

	void DebugRectRender();

private:
	GameEngineLevel* Level_;
	float4 Position_;
	float4 Scale_;

	// ���͸� ������� ������ �����ϴ� �Լ�
	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}

	////////////////////// �׸��� �Ͱ� ������ �ִ� �Լ��� ����

public:
	GameEngineRenderer* CreateRenderer(const std::string& _Image, RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

	GameEngineRenderer* CreateRendererToScale(const std::string& _Image, const float4& _Scale, RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });
	void Rendering();

private:
	std::list<GameEngineRenderer*>::iterator StartRenderIter;
	std::list<GameEngineRenderer*>::iterator EndRenderIter;

	std::list<GameEngineRenderer*> RenderList_;

};

