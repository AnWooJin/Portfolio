#include "HitEffect.h"
#include "HellTakerGame.h"
#include <GameEngine/GameEngineRenderer.h>

HitEffect::HitEffect()
{
}

HitEffect::~HitEffect()
{
}

void HitEffect::Start()
{
	GameEngineRenderer* Render = CreateRenderer();
	if (8 == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount())
	{
		Render->CameraEffectOn();
	}
	Render->CreateAnimation("HitEffect.bmp", "HitEffect", 0, 2, 0.15f, false);
	Render->ChangeAnimation("HitEffect");
	Death(0.45f);
}

void HitEffect::Update()
{

}

void HitEffect::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Death();
}