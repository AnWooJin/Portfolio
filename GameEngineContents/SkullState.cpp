#include "HellTakerGame.h"
#include "Skull.h"
#include "MoveEffect.h"
#include "HitEffect.h"
#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineCollision.h>


void Skull::IdleStart()
{
	MyRenderer_->ChangeAnimation("Skull_Idle");
	StartPos_ = GetPosition();
	EndPos_ = GetPosition();
	Time_ = 0.0f;
}

void Skull::IdleUpdate()
{
	if (MyCollision_->CollisionCheck("Thorn"))
	{
		GameEngineSound::SoundPlayOneShot("Skull_die.wav");
		CreateHitEffect();
		Off();
	}
	else if (MyCollision_->CollisionCheck("Player"))
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
	
	Time_ += GameEngineTime::GetDeltaTime() * 10.0f;
	if (false == GetPosition().CompareInt2D(EndPos_))
	{
		SetPosition(float4::LerpLimit(StartPos_, EndPos_, Time_));
	}
	else if (true == GetPosition().CompareInt2D(EndPos_))
	{
		SkullDeathCheck(GetPosition());
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

	GameEngineActor* Actor = GetLevel()->CreateActor<HitEffect>(7, "Hit");
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
		MovePos = float4::RIGHT * 66;
	}
	else if (GetPosition().x < PlayerPos.x)
	{
		MovePos = float4::LEFT * 66;
	}
	else if (GetPosition().y > PlayerPos.y)
	{
		MovePos = float4::DOWN * 65;
	}
	else if (GetPosition().y < PlayerPos.y)
	{
		MovePos = float4::UP * 65;
	}
	StartPos_ = GetPosition();
	EndPos_ = GetPosition() + MovePos;	
}

void Skull::SkullDeathCheck(float4 _MovePos)
{
	int Color = ColMapImage_->GetImagePixel(_MovePos);
	if (Color == RGB(0, 0, 0))
	{
		GameEngineSound::SoundPlayOneShot("Skull_die.wav");
		Off();
		return;
	}

	
	if (MyCollision_->CollisionCheck("Skull"))
	{
		GameEngineSound::SoundPlayOneShot("Skull_die.wav");
		Off();
	}

	if (MyCollision_->CollisionCheck("Block"))
	{
		GameEngineSound::SoundPlayOneShot("Skull_die.wav");
		Off();
	}

}