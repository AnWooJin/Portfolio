#include "ClearEffect.h"
#include "HellTakerGame.h"
#include <GameEngine/GameEngineRenderer.h>

ClearEffect::ClearEffect()
{
}

ClearEffect::~ClearEffect()
{
}

void ClearEffect::Start()
{
	GameEngineRenderer* Render = CreateRenderer();
	if (8 == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount())
	{
		Render->CameraEffectOn();
	}
	Render->CreateAnimation("ClearEffect.bmp", "ClearEffect", 0, 14, 0.1f, false);
	Render->ChangeAnimation("ClearEffect");
	Death(1.5f);
}

void ClearEffect::Update()
{

}