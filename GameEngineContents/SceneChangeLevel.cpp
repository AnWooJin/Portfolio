#include "SceneChangeLevel.h"
#include "SceneChanger.h"


SceneChangeLevel::SceneChangeLevel()
{
}

SceneChangeLevel::~SceneChangeLevel()
{
}

void SceneChangeLevel::Loading()
{
	CreateActor<SceneChanger>(1);
}

void SceneChangeLevel::Update()
{

}

void SceneChangeLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	
}