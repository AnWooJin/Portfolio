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
// Actor가 기본적으로 가져야 하는 기능들
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
	// 시작할 때 뭔가를 하고 싶지만 생성자에서는 하지 못하는 부분을 담당하는 함수
	virtual void Start() = 0;
	// 지속적으로 게임이 실행될 때 호출되는 함수
	virtual void Update() {}
	// 지속적으로 게임이 실행될 때 엑터의 이미지를 그리는 함수
	virtual void Render() {}

	void DebugRectRender();

private:
	GameEngineLevel* Level_;
	float4 Position_;
	float4 Scale_;

	// 액터를 만들어준 레벨을 설정하는 함수
	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}

	////////////////////// 그리는 것과 연관이 있는 함수와 변수

public:
	GameEngineRenderer* CreateRenderer(const std::string& _Image, RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

	GameEngineRenderer* CreateRendererToScale(const std::string& _Image, const float4& _Scale, RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });
	void Rendering();

private:
	std::list<GameEngineRenderer*>::iterator StartRenderIter;
	std::list<GameEngineRenderer*>::iterator EndRenderIter;

	std::list<GameEngineRenderer*> RenderList_;

};

