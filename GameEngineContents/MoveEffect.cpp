#include "MoveEffect.h"
#include "HellTakerGame.h"
#include <GameEngine/GameEngineRenderer.h>

MoveEffect::MoveEffect()
{
}

MoveEffect::~MoveEffect()
{
}

void MoveEffect::Start()
{
	GameEngineRenderer* Render = CreateRenderer();
	if (8 == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount())
	{
		Render->CameraEffectOn();
	}
	Render->CreateAnimation("Move_Right.bmp", "Move_Right", 0, 2, 0.1f, false);
	Render->ChangeAnimation("Move_Right");
	Render->SetAlpha(160);
	Death(0.3f);
}

void MoveEffect::Update()
{

}

void MoveEffect::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Death();
}