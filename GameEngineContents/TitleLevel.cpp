#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleBackGround.h"
#include "TitleCG.h"


TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Loading()
{
	CreateActor<TitleBackGround>(0);
	CreateActor<TitleCG>(1);

}

void TitleLevel::Update()
{
	//GameEngine::GlobalEngine().ChangeLevel("Play");
}
