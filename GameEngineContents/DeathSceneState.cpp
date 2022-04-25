#include "DeathScene.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>

void DeathScene::AniStart()
{
	SetPosition({ 640, 300 });
	MyRenderer_->ChangeAnimation("DeathScene");
}

void DeathScene::IdleStart()
{
	SetPosition({ 640,360 });
	DeathSceneChange();
}

void DeathScene::Chapter6Start()
{
	SetPosition({ 640,360 });
	MyRenderer_->SetImageAnimationReset("Chapter6_DeathScene.bmp");
	Chapter6Index_ = 0;
	MyRenderer_->SetIndex(Chapter6Index_);
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
	if (true == GameEngineInput::GetInst()->IsDown("Next"))
	{
		//GameEngine::GetInst().ChangeLevel("SceneChange");
	}
}

void DeathScene::Chapter6Update()
{

	if (true == GameEngineInput::GetInst()->IsDown("Next"))
	{
		if (1 == Chapter6Index_)
		{
			//GameEngine::GetInst().ChangeLevel("SceneChange");
			return;
		}
		Chapter6Index_ += 1;
		MyRenderer_->SetIndex(Chapter6Index_);
	}
}


void DeathScene::DeathSceneChange()
{
	switch (Chapter_)
	{
	case 1:
		MyRenderer_->SetImageAnimationReset("Chapter1_DeathScene.bmp");
		break;
	case 2:
		MyRenderer_->SetImageAnimationReset("Chapter2_DeathScene.bmp");
		break;
	case 3:
		MyRenderer_->SetImageAnimationReset("Chapter3_DeathScene.bmp");
		break;
	case 4:
		MyRenderer_->SetImageAnimationReset("Chapter4_DeathScene.bmp");
		break;
	case 5:
		MyRenderer_->SetImageAnimationReset("Chapter5_DeathScene.bmp");
		break;
	case 8:
		MyRenderer_->SetImageAnimationReset("Chapter8_0DeathScene.bmp");
		break;
	default:
		break;
	}
}