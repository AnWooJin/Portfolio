#include "Key.h"
#include "HugeEffect.h"
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineCollision.h>

Key::Key()
	: MyCollision_(nullptr)
{
}

Key::~Key()
{
}

void Key::Start()
{
	GameEngineRenderer* Renderer = CreateRenderer();
	Renderer->CreateAnimation("Key.bmp", "Key", 0, 11, 0.1f, true);
	Renderer->ChangeAnimation("Key");
	MyCollision_ = CreateCollision("Key", { 40, 40 });
}

void Key::Update()
{
	if (true == MyCollision_->CollisionCheck("Player"))
	{
		CreateHugeEffect();
		Off();
	}
}

void Key::CreateHugeEffect()
{
	GameEngineActor* Actor = GetLevel()->CreateActor<HugeEffect>(7);
	Actor->SetPosition(GetPosition());
}