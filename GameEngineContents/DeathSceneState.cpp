#include "DeathScene.h"
#include <GameEngine/GameEngineRenderer.h>

void DeathScene::AniStart()
{
	SetPosition({ 640, 300 });
	MyRenderer_->ChangeAnimation("DeathScene");
}

void DeathScene::IdleStart()
{
	SetPosition({ 640,360 });
	MyRenderer_->SetImageAnimationReset("Chapter8DeathScene.bmp");
}


void DeathScene::AniUpdate()
{
	if (true == MyRenderer_->IsEndAnimation())
	{
		ChangeState(DeathSceneState::Idle);
	}
}

void DeathScene::IdleUpdate()
{

}