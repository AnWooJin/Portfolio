#include "Transition.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>


Transition::Transition()
{
}

Transition::~Transition()
{
}

void Transition::Start()
{
	SetPosition({ 640,360 });
	MyRenderer_ = CreateRenderer();
	MyRenderer_->CreateFolderAnimation("SceneChange", "SceneChange", 0, 28, 0.1f, false);
	MyRenderer_->ChangeAnimation("SceneChange");
}

void Transition::Update()
{
	if (true == MyRenderer_->IsEndAnimation())
	{
		GameEngine::GetInst().ChangeLevel("Play");
	}
}