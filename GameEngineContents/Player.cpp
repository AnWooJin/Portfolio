#include "Player.h"
#include "MoveEffect.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>

Player::Player()
	: MyRenderer_(nullptr)
	 ,ColMapImage_(nullptr)
	 ,KeyCheckTime_(0.15f)
	 ,IsKeyOn_(false)
	 , dir_("Right")
	 , State_("Idle")
	 ,CurState_(PlayerState::Max)
{
}

Player::~Player()
{
}

bool Player::IsMoveKey()
{
	if (false == GameEngineInput::GetInst()->IsPress("MoveRight") &&
		false == GameEngineInput::GetInst()->IsPress("MoveLeft") &&
		false == GameEngineInput::GetInst()->IsPress("MoveUp") &&
		false == GameEngineInput::GetInst()->IsPress("MoveDown"))
	{
		return false;
	}

	return true;
}

void Player::Start()
{
	if (nullptr == MyRenderer_)
	{
		MyRenderer_ = CreateRenderer();
		MyRenderer_->CreateAnimation("Player_Right.bmp", "Player_Idle_Right", 0, 10, 0.075f);
		MyRenderer_->CreateAnimation("Player_Left.bmp", "Player_Idle_Left", 0, 10, 0.075f);
		MyRenderer_->CreateAnimation("Player_Kick_Left.bmp", "Player_Kick_Left", 0, 8, 0.15f);
		MyRenderer_->CreateAnimation("Player_Victory.bmp", "Player_Victory_Left", 0, 18, 0.1f);
		MyRenderer_->ChangeAnimation("Player_Idle_Right");
	}
	


	if (false == GameEngineInput::GetInst()->IsKey("MoveLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("MoveLeft", 'A');
		GameEngineInput::GetInst()->CreateKey("MoveRight", 'D');
		GameEngineInput::GetInst()->CreateKey("MoveUp", 'W');
		GameEngineInput::GetInst()->CreateKey("MoveDown", 'S');
		GameEngineInput::GetInst()->CreateKey("Die", 'K');
	}
	ChangeState(PlayerState::Idle);
}

void Player::Update()
{
	KeyCheckTime_ -= GameEngineTime::GetDeltaTime();
	if (KeyCheckTime_ <= 0)
	{
		IsKeyOn_ = true;
	}
	StateUpdate();
}


void Player::Render()
{

}

void Player::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}



void Player::ChangeState(PlayerState _State)
{
	if (CurState_ == _State)
	{
		return;
	}
	switch (_State)
	{
	case PlayerState::Idle:
		IdleStart();
		State_ = "Idle";
		break;
	case PlayerState::Move:
		MoveStart();
		State_ = "Move";
		break;
	case PlayerState::Attack:
		AttackStart();
		State_ = "Attack";
		break;
	case PlayerState::Victory:
		VictoryStart();
		State_ = "Victory";
		break;
	case PlayerState::Max:
		break;
	default:
		break;
	}
	ChangeAnimation();
	CurState_ = _State;
}

void Player::StateUpdate()
{
	switch (CurState_)
	{
	case PlayerState::Idle:
		IdleUpdate();
		break;
	case PlayerState::Move:
		MoveUpdate();
		break;
	case PlayerState::Attack:
		AttackUpdate();
		break;
	case PlayerState::Victory:
		VictoryUpdate();
		break;
	case PlayerState::Max:
		break;
	default:
		break;
	}
}

void Player::PlayerSetting(int _Chapter)
{
	switch (_Chapter)
	{
	case 1:
		SetPosition({ 774,175 });
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter1_ColMap.bmp");
		break;
	case 2:
		SetPosition({ 440,435 });
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter2_ColMap.bmp");
		break;
	case 3:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter3_ColMap.bmp");
		break;
	case 4:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter4_ColMap.bmp");
		break;
	case 5:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter5_ColMap.bmp");
		break;
	case 6:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter6_ColMap.bmp");
		break;
	case 7:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter7_ColMap.bmp");
		break;
	case 8:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter8_ColMap.bmp");
		break;
	case 9:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter9_ColMap.bmp");
		break;
	default:
		break;
	}
}