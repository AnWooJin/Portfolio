#include "HellTakerGame.h"
#include "Skull.h"
#include <GameEngine/GameEngine.h>

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
		
}