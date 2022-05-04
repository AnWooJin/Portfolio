#include "Player.h"
#include "MoveEffect.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>

Player::Player()
	: MyRenderer_(nullptr)
	, BlackBackGround_(nullptr)
	, ColMapImage_(nullptr)
	, MovePos_(float4::ZERO)
	, Time_(0.3f)
	, HasKey_(false)
	, dir_("Right")
	, State_("Idle")
	, MoveCount_(11)
	, CurState_(PlayerState::Max)
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
		MyRenderer_->CreateAnimation("Player_Idle_Right.bmp", "Player_Idle_Right", 0, 10, 0.075f);
		MyRenderer_->CreateAnimation("Player_Idle_Left.bmp", "Player_Idle_Left", 0, 10, 0.075f);
		MyRenderer_->CreateAnimation("Player_Move_Right.bmp", "Player_Move_Right", 0, 5, 0.075f,false);
		MyRenderer_->CreateAnimation("Player_Move_Left.bmp", "Player_Move_Left", 0, 5, 0.075f, false);
		MyRenderer_->CreateAnimation("Player_Kick_Left.bmp", "Player_Attack_Left", 0, 8, 0.05f);
		MyRenderer_->CreateAnimation("Player_Kick_Right.bmp", "Player_Attack_Right", 0, 8, 0.05f);
		MyRenderer_->CreateAnimation("Player_Victory.bmp", "Player_Victory_Left", 0, 18, 0.1f);
		MyRenderer_->CreateAnimation("Player_Death.bmp", "Player_Death", 0, 17, 0.1f);
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
	MyCollision_ = CreateCollision("Player", {30,30 });
	MyCollision_->CameraEffectOn();
	MyRenderer_->CameraEffectOn();
	ChangeState(PlayerState::Idle);
	LevelRegist("Player");
}

void Player::Update()
{
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
	CurState_ = _State;
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
	case PlayerState::Death:
		DeathStart();
		State_ = "Death";
		break;
	case PlayerState::Max:
		break;
	default:
		break;
	}
	ChangeAnimation();	
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
	case PlayerState::Death:
		DeathUpdate();
		break;
	case PlayerState::Max:
		break;
	default:
		break;
	}
}

void Player::PlayerSetting(int _Chapter)
{
	ChangeState(PlayerState::Idle);
	dir_ = "_Right";
	StartPos_ = GetPosition();
	EndPos_ = GetPosition();
	switch (_Chapter)
	{
	case 1:
		SetPosition({ 774,175 });
		
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter1_ColMap.bmp");
		MoveCount_ = 23;
		break;
	case 2:
		SetPosition({ 440,435 });
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter2_ColMap.bmp");
		MoveCount_ = 24;
		break;
	case 3:
		SetPosition({ 870,274 });
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter3_ColMap.bmp");
		MoveCount_ = 132;
		break;
	case 4:
		SetPosition({ 405,212 });
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter4_ColMap.bmp");
		MoveCount_ = 23;
		break;
	case 5:
		SetPosition({ 475,274 });
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter5_ColMap.bmp");
		MoveCount_ = 23;
		break;
	case 6:
		SetPosition({ 575,114 });
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter6_ColMap.bmp");
		MoveCount_ = 43;
		break;
	case 7:
		SetPosition({ 805,404 });
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter7_ColMap.bmp");
		MoveCount_ = 32;
		break;
	case 8:
		SetPosition({ 640,1140 });
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter8_ColMap.bmp");
		MoveCount_ = 12;
		break;
	case 9:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter9_ColMap.bmp");
		MoveCount_ = 33;
		break;
	default:
		break;
	}
}