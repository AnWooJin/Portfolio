#include "DeathScene.h"
#include "HellTakerGame.h"
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineWindow.h>

DeathScene::DeathScene()
	: MyRenderer_(nullptr),
	  CurState_(DeathSceneState::Max),
	  Chapter_(0)
{
}

DeathScene::~DeathScene()
{
}

void DeathScene::Start()
{
	if (false == GameEngineInput::GetInst()->IsKey("Next"))
	{
		GameEngineInput::GetInst()->CreateKey("Next", VK_SPACE);
	}

	if (MyRenderer_ == nullptr)
	{
		MyRenderer_ = CreateRenderer();
	}
	MyRenderer_->CreateAnimation("DeathScene.bmp", "DeathScene", 0, 8, 0.1f);
	CreateRenderer("BlackBG.bmp", 0)->SetPivot({0, 60});

	ChangeState(DeathSceneState::Ani);
}

void DeathScene::Update()
{
	StateUpdate();
}

void DeathScene::Render()
{

}


void DeathScene::ChangeState(DeathSceneState _State)
{
	if (CurState_ == _State)
	{
		return;
	}

	CurState_ = _State;

	switch (CurState_)
	{
	case DeathSceneState::Ani:
		AniStart();
		break;
	case DeathSceneState::Idle:
		IdleStart();
		break;
	case DeathSceneState::Max:
		break;
	default:
		break;
	}
}

void DeathScene::StateUpdate()
{
	switch (CurState_)
	{
	case DeathSceneState::Ani:
		AniUpdate();
		break;
	case DeathSceneState::Idle:
		IdleUpdate();
		break;
	case DeathSceneState::Max:
		break;
	default:
		break;
	}
}
