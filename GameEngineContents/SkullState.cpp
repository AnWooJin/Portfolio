#include "HellTakerGame.h"
#include "Skull.h"
#include "MoveEffect.h"
#include "HitEffect.h"
#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngine/GameEngineImage.h>
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
	
	if (true == MyRenderer_->IsEndAnimation())
	{
		ChangeState(SkullState::Idle);
	}

}

void Skull::CreateMoveEffect()
{

	GameEngineActor* Actor = GetLevel()->CreateActor<MoveEffect>(1, "Move");
	Actor->SetPosition(GetPosition() + (float4::DOWN * 20.0f));
	if (8 == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount())
	{
		Actor->SetPosition(GetLevel()->GetCameraPos() + GetPosition() + (float4::DOWN * 20.0f));
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
	float4 MovePos = float4::ZERO;

	if (GetPosition().x > PlayerPos.x)
	{
		MovePos = float4::RIGHT * 65;
	}
	if (GetPosition().x < PlayerPos.x)
	{
		MovePos = float4::LEFT * 65;
	}
	if (GetPosition().y > PlayerPos.y)
	{
		MovePos = float4::DOWN * 65;
	}
	if (GetPosition().y < PlayerPos.y)
	{
		MovePos = float4::UP * 65;
	}


	SkullDeathCheck(MovePos);
	
}

void Skull::SkullDeathCheck(float4 _MovePos)
{
	int Color = ColMapImage_->GetImagePixel(GetPosition() + _MovePos + GetLevel()->GetCameraPos());
	if (Color == RGB(0, 0, 0))
	{
		GameEngineSound::SoundPlayOneShot("Skull_die.wav");
		Off();
		return;
	}

	SetMove(_MovePos);
	
	if (MyCollision_->CollisionCheck("Skull"))
	{
		GameEngineSound::SoundPlayOneShot("Skull_die.wav");
		Off();
	}


}