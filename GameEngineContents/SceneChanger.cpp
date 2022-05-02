#include "SceneChanger.h"
#include  <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngine.h>

SceneChanger::SceneChanger()
	: MyRenderer_(nullptr),
	  PlayOpenSound_(false),
	  PlayCloseSound_(false)
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
	if (false == PlayOpenSound_)
	{
		GameEngineSound::SoundPlayOneShot("SceneChangerOpen.wav");
		PlayOpenSound_ = true;
	}

	if (false == PlayCloseSound_ && 21 == MyRenderer_->CurrentAnimation()->WorldCurrentFrame())
	{
		GameEngineSound::SoundPlayOneShot("SceneChangerClose.wav");
		PlayCloseSound_ = true;
	}

	if (MyRenderer_->IsEndAnimation())
	{
		GameEngine::GetInst().ChangeLevel("Play");
	
	}
}

void SceneChanger::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	PlayOpenSound_ = false;
	PlayCloseSound_ = false;
}