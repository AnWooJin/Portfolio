#include "HellTakerGame.h"
#include "Skull.h"
#include "MoveEffect.h"
#include "HitEffect.h"
#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineCollision.h>

Skull::Skull()
{
}

Skull::~Skull()
{
}

void Skull::Start()
{
	MyRenderer_ = CreateRenderer();
	MyRenderer_->CreateAnimation("Skull_Nomal.bmp", "Skull_Nomal", 0, 11, 0.065f);
	MyRenderer_->ChangeAnimation("Skull_Nomal");
	MyCollision_ = CreateCollision("Skull", { 60,60});
	MyPlayer_ = GetLevel()->FindActor<Player>("Player");
}

void Skull::Update()
{
	if (8 == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount())
	{
		MyRenderer_->CameraEffectOn();
	}
	else
	{
		MyRenderer_->CameraEffectOff();
	}
	float4 CheckPos = MyPlayer_->GetPlayerMovePos();
	CheckPos *= {-1.0f, -1.0f};

	if (MyCollision_->CollisionCheck("Player"))
	{
		CreateMoveEffect();
		CreateHitEffect();
		SkullPush();
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
