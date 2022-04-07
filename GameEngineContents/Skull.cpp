#include "Skull.h"

Skull::Skull()
{
}

Skull::~Skull()
{
}

void Skull::Start()
{
	GameEngineRenderer* Render = CreateRenderer();
	Render->CreateAnimation("Skull_Nomal.bmp", "Skull_Nomal", 0, 11, 0.065f);
	Render->ChangeAnimation("Skull_Nomal");
}

void Skull::Update()
{

}