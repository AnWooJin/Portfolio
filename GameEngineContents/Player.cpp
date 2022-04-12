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
	: MyRender_(nullptr)
	 ,ColMapImage_(nullptr)
	 ,MyMoveRender_(nullptr)
	 ,KeyCheckTime_(0.2f)
	 ,IsKeyOn_(false)
{
}

Player::~Player()
{
}

bool Player::IsMoveKey()
{
	if (false == GameEngineInput::GetInst()->IsDown("MoveRight") &&
		false == GameEngineInput::GetInst()->IsDown("MoveLeft") &&
		false == GameEngineInput::GetInst()->IsDown("MoveUp") &&
		false == GameEngineInput::GetInst()->IsDown("MoveDown"))
	{
		return false;
	}

	return true;
}

void Player::Start()
{
	if (nullptr == MyRender_)
	{
		MyRender_ = CreateRenderer();
		MyRender_->CreateAnimation("Player_Right.bmp", "Player_Right", 0, 10, 0.075f);
		MyRender_->CreateAnimation("Player_Left.bmp", "Player_Left", 0, 10, 0.075f);
		MyRender_->CreateAnimation("Player_Kick_Left.bmp", "Player_Kick_Left", 0, 8, 0.15f);
		MyRender_->CreateAnimation("Player_Victory.bmp", "Player_Victory", 0, 18, 0.1f);
		MyRender_->ChangeAnimation("Player_Right");
	}
	


	if (false == GameEngineInput::GetInst()->IsKey("MoveLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("MoveLeft", 'A');
		GameEngineInput::GetInst()->CreateKey("MoveRight", 'D');
		GameEngineInput::GetInst()->CreateKey("MoveUp", 'W');
		GameEngineInput::GetInst()->CreateKey("MoveDown", 'S');
		GameEngineInput::GetInst()->CreateKey("Die", 'K');
	}
}

void Player::Update()
{

	KeyCheckTime_ -= GameEngineTime::GetDeltaTime();
	if (KeyCheckTime_ <= 0)
	{
		IsKeyOn_ = true;
	}
	if (true == IsMoveKey())
	{
		KeyCheck();
	}
}


void Player::Render()
{

}


void Player::KeyCheck()
{
	float4 NextPos = GetPosition();
	if (true == IsKeyOn_)
	{
		if (true == GameEngineInput::GetInst()->IsDown("MoveLeft"))
		{
			MyRender_->ChangeAnimation("Player_Left");
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
			NextPos += float4::LEFT * 66;
		}
		else if (true == GameEngineInput::GetInst()->IsDown("MoveRight"))
		{
			MyRender_->ChangeAnimation("Player_Right");
			NextPos += float4::RIGHT * 66;
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
		}

		else if (true == GameEngineInput::GetInst()->IsDown("MoveUp"))
		{
			NextPos += float4::UP * 65;
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
		}

		else if (true == GameEngineInput::GetInst()->IsDown("MoveDown"))
		{
			NextPos += float4::DOWN * 65;
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
		}
		else if (true == GameEngineInput::GetInst()->IsDown("Die"))
		{
			GameEngine::GetInst().ChangeLevel("Title");
			/*MyRender_->ChangeAnimation("Player_Victory");
			NextPos = GetPosition() + (float4::UP * 6);*/
		}

		else if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
		{
			MyRender_->ChangeAnimation("Player_Left");
			NextPos += float4::LEFT * 66;
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
		}

		else if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
		{
			MyRender_->ChangeAnimation("Player_Right");
			NextPos += float4::RIGHT * 66;
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
		}

		else if (true == GameEngineInput::GetInst()->IsPress("MoveUp"))
		{
			NextPos += float4::UP * 65;
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
		}

		else if (true == GameEngineInput::GetInst()->IsPress("MoveDown"))
		{
			
			NextPos += float4::DOWN * 65;
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
		}	
		int Color = ColMapImage_->GetImagePixel(NextPos);
		if (RGB(0, 0, 0) != Color)
		{
			CreateMoveEffect();
			SetPosition(NextPos);
		}
	}
	
}

void Player::CreateMoveEffect()
{
	GameEngineActor* Actor = GetLevel()->CreateActor<MoveEffect>(1, "Move");
	Actor->SetPosition(GetPosition());
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