#include "BloodEffect.h"
#include "HellTakerGame.h"
#include <GameEngine/GameEngineRenderer.h>


BloodEffect::BloodEffect()
{
}

BloodEffect::~BloodEffect()
{
}

void BloodEffect::Start()
{
	
	{
		GameEngineRenderer* Render = CreateRenderer();
		Render->CreateAnimation("BloodEffect_2.bmp", "BloodEffect_2", 0, 5, 0.05f, false);
		Render->SetPivot({ 0.0f, 20.0f });
		Render->ChangeAnimation("BloodEffect_2");
	}

	Death(0.3f);
}

void BloodEffect::Update()
{

}

void BloodEffect::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Death();
}