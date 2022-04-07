#include "MoveAni.h"
#include <GameEngine/GameEngineRenderer.h>

MoveAni::MoveAni()
{
}

MoveAni::~MoveAni()
{
}

void MoveAni::Start()
{
	GameEngineRenderer* Render = CreateRenderer();

	Render->CreateAnimation("Move_Right", "Move_Right", 0, 2, 0.1f, false);

	Death(0.3f);
}

void MoveAni::Update()
{

}