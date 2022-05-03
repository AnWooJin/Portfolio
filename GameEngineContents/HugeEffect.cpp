#include "HugeEffect.h"
#include <GameEngine/GameEngineRenderer.h>

HugeEffect::HugeEffect()
{
}

HugeEffect::~HugeEffect()
{
}

void HugeEffect::Start()
{
	GameEngineRenderer* Render = CreateRenderer();
	Render->CreateAnimation("HugeEffect.bmp", "HugeEffect", 0, 8, 0.08f, false);
	Render->ChangeAnimation("HugeEffect");
	Death(0.8f);
}

void HugeEffect::Update()
{

}

void HugeEffect::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Death();
}