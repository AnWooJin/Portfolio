#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineUpdateObject.h>
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineEnum.h"
#include <list>

class GameEngineLevel;
class GameEngineRenderer;
class GameEngineCollision;
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

	inline void ResetIgnoreOn()
	{
		IsResetIgnore = true;
	}

	float4 GetCameraEffectPostion();

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

	inline void NextLevelOn()
	{
		NextLevelOn_ = true;
	}

	void SetOrder(int _Order) override;

protected:
	// 시작할 때 뭔가를 하고 싶지만 생성자에서는 하지 못하는 부분을 담당하는 함수
	virtual void Start() = 0;
	// 지속적으로 게임이 실행될 때 호출되는 함수
	virtual void Update() {}
	// 지속적으로 게임이 실행될 때 엑터의 이미지를 그리는 함수
	virtual void Render() {}

	virtual void LevelChangeStart(GameEngineLevel* _PrevLevel) {}
	virtual void LevelChangeEnd(GameEngineLevel* _NextLevel) {};

	void Release();

	void DebugRectRender();

	void LevelRegist(std::string _RegistName = "");

private:
	GameEngineLevel* Level_;
	float4 Position_;
	float4 Scale_;

	bool NextLevelOn_;
	bool IsResetIgnore;

	inline void NextLevelOff()
	{
		NextLevelOn_ = false;
	}

	// 액터를 만들어준 레벨을 설정하는 함수
	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}

	////////////////////// 그리는 것과 연관이 있는 함수와 변수

public:
	GameEngineRenderer* CreateRenderer(int _Order = static_cast<int>(EngineMax::RENDERORDERMAX),RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

	GameEngineRenderer* CreateRenderer(const std::string& _Image, int _Order = static_cast<int>(EngineMax::RENDERORDERMAX), RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

	GameEngineRenderer* CreateRendererToScale(const std::string& _Image, const float4& _Scale, int _Order = static_cast<int>(EngineMax::RENDERORDERMAX), RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });
	void Rendering();

private:
	std::list<GameEngineRenderer*>::iterator StartRenderIter;
	std::list<GameEngineRenderer*>::iterator EndRenderIter;

	std::list<GameEngineRenderer*> RenderList_;


	///////////////////////////////////////////////////////////////////////////////////////////// Collision

public:
	GameEngineCollision* CreateCollision(const std::string& _GroupName, float4 _Scale, float4 _Pivot = { 0, 0 });


private:
	// 이터레이터
	std::list<GameEngineCollision*> CollisionList_;
};

