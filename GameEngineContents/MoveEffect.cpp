#include "MoveEffect.h"
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

	Render->CreateAnimation("Move_Right.bmp", "Move_Right", 0, 2, 0.1f, false);
	Render->ChangeAnimation("Move_Right");
	Death(0.3f);
}

void MoveEffect::Update()
{

}