#include "Booper.h"
#include <GameEngine/GameEngineRenderer.h>

Booper::Booper()
{
}

Booper::~Booper()
{
}

void Booper::Start()
{
	SetPosition({ 640, 630 });
	GameEngineRenderer* Renderer = CreateRenderer();
	Renderer->CreateAnimation("Booper.bmp", "Booper", 0, 18, 0.1f);
	Renderer->ChangeAnimation("Booper");
}

void Booper::Update()
{

}