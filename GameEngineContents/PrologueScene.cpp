#include "PrologueScene.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>

PrologueScene::PrologueScene()
	: MyRenderer_(nullptr)
{
}

PrologueScene::~PrologueScene()
{
}

void PrologueScene::Start()
{
	SetPosition({ 640,360 });
	MyRenderer_ = CreateRenderer();
	MyRenderer_->CreateFolderAnimation("SceneChange", "SceneChange", 0, 28, 0.1f, false);
	MyRenderer_->ChangeAnimation("SceneChange");
}

void PrologueScene::Update()
{
	if (true == MyRenderer_->IsEndAnimation())
	{
		GameEngine::GetInst().ChangeLevel("Play");
	}
}