#include "EpilogueLevel.h"
#include "EpilogueScene.h"
#include "Booper.h"
#include <GameEngineBase/GameEngineSound.h>

EpilogueLevel::EpilogueLevel()
{
}

EpilogueLevel::~EpilogueLevel()
{
}


void EpilogueLevel::Loading()
{
	CreateActor<EpilogueScene>(0);
	CreateActor<Booper>(1);
}

void EpilogueLevel::Update()
{
	
}

void EpilogueLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	GameEngineSound::SoundPlayOneShot("dialogue_start_epilogue_01.wav");
}

