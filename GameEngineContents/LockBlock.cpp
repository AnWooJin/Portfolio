#include "LockBlock.h"
#include <GameEngine/GameEngineLevel.h>
#include "Player.h"
#include "HugeEffect.h"
#include <GameEngine/GameEngineCollision.h>
#include <GameEngineBase/GameEngineSound.h>

LockBlock::LockBlock()
	: MyRenderer_(nullptr)
	, MyCollision_(nullptr)
	, MyPlayer_(nullptr)
{
}

LockBlock::~LockBlock()
{
}

void LockBlock::Start()
{
	MyRenderer_ = CreateRenderer("LockBlock.bmp");
	MyCollision_ = CreateCollision("LockBlock", { 40,40 });
	MyPlayer_ = GetLevel()->FindActor<Player>("Player");
}

void LockBlock::Update()
{
	if (MyCollision_->CollisionCheck("Player"))
	{
		KeyCheck();
	}
}

void LockBlock::KeyCheck()
{
	if (true == MyPlayer_->GetHasKey())
	{
		GameEngineSound::SoundPlayOneShot("LockBlock_Open.wav");
		CreateHugeEffect();
		Off();
	}
}

void LockBlock::CreateHugeEffect()
{
	GameEngineActor* Actor = GetLevel()->CreateActor<HugeEffect>(7);
	Actor->SetPosition(GetPosition());
}