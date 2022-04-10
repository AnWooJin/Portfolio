#include "Thorn.h"
#include <GameEngine/GameEngineRenderer.h>

Thorn::Thorn()
{
}

Thorn::~Thorn()
{
}

void Thorn::Start()
{
	GameEngineRenderer* Render = CreateRenderer("Thorn.bmp");
	SetPosition({ 510, 435 + 20 });
}