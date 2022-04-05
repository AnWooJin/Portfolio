#include "Player.h"
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
	SetPosition({ 774,175 });
	
	MyRender_ = CreateRenderer();
	MyMoveRender_ = CreateRenderer();
	MapColImage_ = GameEngineImageManager::GetInst()->Find("chapterBG01_Col.bmp");
	MyRender_->CreateAnimation("Player_Right.bmp", "Player_Right", 0, 10, 0.15f);
	MyRender_->CreateAnimation("Player_Left.bmp", "Player_Left", 0, 10, 0.15f);
	MyRender_->CreateAnimation("Player_Kick_Left.bmp", "Player_Kick_Left", 0, 8, 0.15f);
	MyMoveRender_->CreateAnimation("Move_Right.bmp", "Move_Right", 0, 2, 0.3f, true);
	MyMoveRender_->ChangeAnimation("Move_Right");
	MyMoveRender_->Off();
	MyRender_->ChangeAnimation("Player_Right");


	if (false == GameEngineInput::GetInst()->IsKey("MoveLeft"));
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
			MyRender_->ChangeAnimation("Player_Left");
			MyMoveRender_->SetPivot({65,0});
			MyMoveRender_->On();
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
			MyRender_->ChangeAnimation("Player_Kick_Left");
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
	}
	int Color = MapColImage_->GetImagePixel(NextPos);
	if (RGB(0, 0, 0) != Color)
	{
		SetPosition(NextPos);
	}
}
