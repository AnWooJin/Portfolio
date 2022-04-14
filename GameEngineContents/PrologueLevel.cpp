#include "PrologueLevel.h"
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