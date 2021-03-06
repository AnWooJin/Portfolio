#pragma once
#include "GameEngineActorSubObject.h"
#include "GameEngineEnum.h"
#include <map>
#include <vector>

class GameEngineImage;
class GameEngineCollision : public GameEngineActorSubObject
{
	friend GameEngineActor;
	friend GameEngineLevel;
public:
	//construcuter destructer
	GameEngineCollision();
	~GameEngineCollision();

	//delete Function
	GameEngineCollision(const GameEngineCollision& _Other) = delete;
	GameEngineCollision(GameEngineCollision&& _Other) noexcept = delete;
	GameEngineCollision& operator=(const GameEngineCollision& _Other) = delete;
	GameEngineCollision& operator=(GameEngineCollision&& _Other) noexcept = delete;

	inline void SetPivot(const float4& _Pos)
	{
		Pivot_ = _Pos;
	}

	inline void SetScale(const float4& _Scale)
	{
		Scale_ = _Scale;
	}

	inline float4 GetCollisionPos()
	{
		return GetActor()->GetPosition() + Pivot_;
	}

	inline GameEngineRect GetRect()
	{
		return GameEngineRect(GetActor()->GetPosition() + Pivot_ + NextPos_, Scale_);
	}

	void CameraEffectOff()
	{
		IsCameraEffect_ = false;
	}

	void CameraEffectOn()
	{
		IsCameraEffect_ = true;
	}

	bool CollisionCheck(
		const std::string& _TargetGroup,
		CollisionType _This = CollisionType::Rect,
		CollisionType _Target = CollisionType::Rect
	);

	bool NextPosCollisionCheck(
		const std::string& _TargetGroup,
		float4 NextPos,
		CollisionType _This = CollisionType::Rect,
		CollisionType _Target = CollisionType::Rect
	);

	bool CollisionResult(
		const std::string& _TargetGroup,
		std::vector<GameEngineCollision*>& _ColResult,
		CollisionType _This = CollisionType::Rect,
		CollisionType _Target = CollisionType::Rect
	);

	void DebugRender();

private:
	friend class FrameAnimation;
	float4 Pivot_;
	float4 Scale_;
	float4 NextPos_;
	bool IsCameraEffect_;

	std::string CollisionName_;

	void NextPosReset()
	{
		NextPos_ = float4::ZERO;
	}
};

