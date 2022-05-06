#include "HellTakerGame.h"
#include "SceneChangeLevel.h"
#include "SceneChanger.h"
#include <GameEngine/GameEngine.h>


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

void SceneChangeLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	HellTakerGame& MyGame = dynamic_cast<HellTakerGame&>(GameEngine::GetInst());
	if (true == MyGame.GetIsSuccess())
	{
		MyGame.IsSuccesssOff();
		MyGame.NextChapterCount();
	}
}