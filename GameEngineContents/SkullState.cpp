#include "HellTakerGame.h"
#include "Skull.h"
#include "MoveEffect.h"
#include "HitEffect.h"
#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineCollision.h>


void Skull::IdleStart()
{
	MyRenderer_->ChangeAnimation("Skull_Idle");
}

void Skull::IdleUpdate()
{

	if (MyCollision_->CollisionCheck("Player"))
	{
		CreateMoveEffect();
		CreateHitEffect();
		SkullPush();
		ChangeState(SkullState::Hit);
	}
}

void Skull::HitStart()
{
	MyRenderer_->ChangeAnimation("Skull_Hit");
}


void Skull::HitUpdate()
{
	SkullDeathCheck();
	if (true == MyRenderer_->IsEndAnimation())
	{
		ChangeState(SkullState::Idle);
	}

}

void Skull::CreateMoveEffect()
{

	GameEngineActor* Actor = GetLevel()->CreateActor<MoveEffect>(1, "Move");
	Actor->SetPosition(GetPosition() + (float4::DOWN * 5.0f));
	if (8 == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount())
	{
		Actor->SetPosition(GetLevel()->GetCameraPos() + GetPosition() + (float4::DOWN * 5.0f));
	}
}

void Skull::CreateHitEffect()
{

	GameEngineActor* Actor = GetLevel()->CreateActor<HitEffect>(1, "Hit");
	Actor->SetPosition(GetPosition());
	if (8 == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount())
	{
		Actor->SetPosition(GetLevel()->GetCameraPos() + GetPosition());
	}
}


void Skull::SkullPush()
{
	float4 PlayerPos = MyPlayer_->GetPosition();

	if (GetPosition().x > PlayerPos.x)
	{
		SetMove(float4::RIGHT * 65);
	}
	if (GetPosition().x < PlayerPos.x)
	{
		SetMove(float4::LEFT * 65);
	}
	if (GetPosition().y > PlayerPos.y)
	{
		SetMove(float4::DOWN * 65);
	}
	if (GetPosition().y < PlayerPos.y)
	{
		SetMove(float4::UP * 65);
	}


	
}

void Skull::SkullDeathCheck()
{
	if (MyCollision_->CollisionCheck("Skull"))
	{
		Off();
	}
}