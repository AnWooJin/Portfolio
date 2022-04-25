#include "DeathLevel.h"
#include "DeathScene.h"

DeathLevel::DeathLevel()
{
}

DeathLevel::~DeathLevel()
{
}

void DeathLevel::Loading()
{
	CreateActor<DeathScene>(1);
}

void DeathLevel::Update()
{

}

void DeathLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}