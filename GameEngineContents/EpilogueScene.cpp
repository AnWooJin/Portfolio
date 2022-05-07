#include "EpilogueScene.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>

EpilogueScene::EpilogueScene()
	:SceneRenderer_(nullptr)
	,ScenePage_(0)
{
}

EpilogueScene::~EpilogueScene()
{
}


void EpilogueScene::Start()
{
	SceneRenderer_ = CreateRenderer();
	if (false == GameEngineInput::GetInst()->IsKey("Next"))
	{
		GameEngineInput::GetInst()->CreateKey("Next", VK_SPACE);
	}
	SceneRenderer_->SetImage("EpilogueScene.bmp");
	SetPosition({ 640, 360 });
}

void EpilogueScene::Update()
{
	SceneRenderer_->SetIndex(ScenePage_);
	if (true == GameEngineInput::GetInst()->IsDown("Next"))
	{
		GameEngineSound::SoundPlayOneShot("dialogue_text_end_01.wav");
		if (11 == ScenePage_)
		{
			GameEngine::GetInst().ChangeLevel("SceneChange");
			return;
		}
		++ScenePage_;
	}
}

void EpilogueScene::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	ScenePage_ = 0;
}