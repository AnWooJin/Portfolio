#include "SceneChanger.h"
#include  <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngine.h>

SceneChanger::SceneChanger()
	: MyRenderer_(nullptr)
{
}

SceneChanger::~SceneChanger()
{
}

void SceneChanger::Start()
{
	SetPosition({ 640,360 });
	MyRenderer_ = CreateRenderer();
	MyRenderer_->CreateFolderAnimation("SceneChange", "SceneChange", 0, 28, 0.05f, true);
	MyRenderer_->ChangeAnimation("SceneChange");
}

void SceneChanger::Update()
{
	if (MyRenderer_->IsEndAnimation())
	{
		GameEngine::GetInst().ChangeLevel("Play");
	}
}

void SceneChanger::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}