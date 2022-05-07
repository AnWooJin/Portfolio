#include "DeathLevel.h"
#include "DeathScene.h"
#include <GameEngineBase/GameEngineSound.h>

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
	GameEngineSound::SoundPlayOneShot("DeathScene.wav");
}