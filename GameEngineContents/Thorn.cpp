#include "Thorn.h"
#include "HellTakerGame.h"
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineCollision.h>

Thorn::Thorn()
{
}

Thorn::~Thorn()
{
}

void Thorn::Start()
{
	GameEngineRenderer* Render = CreateRenderer("Thorn.bmp");
	MyCollision_ = CreateCollision("Thorn", { 40,40 });
}

void Thorn::Update()
{

}

void Thorn::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	Death();
}