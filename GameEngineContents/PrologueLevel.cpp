#include "PrologueLevel.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineSound.h>
#include "BlackBackGround.h"
#include "PrologueScene.h"

PrologueLevel::PrologueLevel()
{
}

PrologueLevel::~PrologueLevel()
{
}

void PrologueLevel::Loading()
{
	CreateActor<BlackBackGround>(0);
	CreateActor<PrologueScene>(1);
}

void PrologueLevel::LevelChangeEnd()
{
}