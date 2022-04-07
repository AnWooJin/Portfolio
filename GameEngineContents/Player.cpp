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
	: MyRender_(nullptr),
	 KeyCheckTime_(0.2f),
	 IsKeyOn_(false)
{
}

Player::~Player()
{
}

void Player::Start()
{
	SetPosition({ 774,175});
	if (nullptr == MyRender_)
	{
		MyRender_ = CreateRenderer();
		MapColImage_ = GameEngineImageManager::GetInst()->Find("chapter1_ColMap.bmp");
		MyRender_->CreateAnimation("Player_Right.bmp", "Player_Right", 0, 10, 0.075f);
		MyRender_->CreateAnimation("Player_Left.bmp", "Player_Left", 0, 10, 0.075f);
		MyRender_->CreateAnimation("Player_Kick_Left.bmp", "Player_Kick_Left", 0, 8, 0.15f);
		MyRender_->CreateAnimation("Player_Victory.bmp", "Player_Victory", 0, 18, 0.1f);
		MyRender_->ChangeAnimation("Player_Victory");
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
	KeyCheck();
	int Color = MapColImage_->GetImagePixel(GetPosition());

	if (RGB(0, 0, 0) == Color)
	{
		int a = 0;
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
			CreateMoveEffect();
			MyRender_->ChangeAnimation("Player_Left");
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
			NextPos += float4::LEFT * 66;
		}
		else if (true == GameEngineInput::GetInst()->IsDown("MoveRight"))
		{
			CreateMoveEffect();
			MyRender_->ChangeAnimation("Player_Right");
			NextPos += float4::RIGHT * 66;
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
		}

		else if (true == GameEngineInput::GetInst()->IsDown("MoveUp"))
		{
			CreateMoveEffect();
			NextPos += float4::UP * 65;
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
		}

		else if (true == GameEngineInput::GetInst()->IsDown("MoveDown"))
		{
			CreateMoveEffect();
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
			CreateMoveEffect();
			MyRender_->ChangeAnimation("Player_Left");
			NextPos += float4::LEFT * 66;
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
		}

		else if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
		{
			CreateMoveEffect();
			MyRender_->ChangeAnimation("Player_Right");
			NextPos += float4::RIGHT * 66;
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
		}

		else if (true == GameEngineInput::GetInst()->IsPress("MoveUp"))
		{
			CreateMoveEffect();
			NextPos += float4::UP * 65;
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
		}

		else if (true == GameEngineInput::GetInst()->IsPress("MoveDown"))
		{
			CreateMoveEffect();
			NextPos += float4::DOWN * 65;
			IsKeyOn_ = false;
			KeyCheckTime_ = 0.2f;
		}	
	}
	int Color = MapColImage_->GetImagePixel(NextPos);
	if (RGB(0, 0, 0) != Color)
	{
		SetPosition(NextPos);
	}
}

void Player::CreateMoveEffect()
{
	GameEngineActor* Actor = GetLevel()->CreateActor<MoveEffect>(1, "Move");
	Actor->SetPosition(GetPosition());
}