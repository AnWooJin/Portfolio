#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	SetPosition({ 742,400 });
	GameEngineRenderer* Render = CreateRenderer("Player_Right.bmp");
	Render->CreateAnimation("Player_Right.bmp", "Player", 0, 10, 0.08f);
	Render->ChangeAnimation("Player");


	if (false == GameEngineInput::GetInst()->IsKey("MoveLeft"));
	{
		GameEngineInput::GetInst()->CreateKey("MoveLeft", 'A');
		GameEngineInput::GetInst()->CreateKey("MoveRight", 'D');
		GameEngineInput::GetInst()->CreateKey("MoveUp", 'W');
		GameEngineInput::GetInst()->CreateKey("MoveDown", 'S');
		GameEngineInput::GetInst()->CreateKey("PlayerJump", VK_LSHIFT);
		GameEngineInput::GetInst()->CreateKey("Fire", VK_SPACE);
	}
}

void Player::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("MoveLeft"))
	{
		GameEngineRenderer* Render = CreateRenderer("Player_Left.bmp");
		Render->CreateAnimation("Player_Left.bmp", "Player", 0, 10, 0.08f);
		Render->ChangeAnimation("Player");
		SetPosition(GetPosition() + float4{ -80.0f,0.0f });
		
	}

	if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
	{
		SetMove(float4::RIGHT);
	}

	if (true == GameEngineInput::GetInst()->IsPress("MoveUp"))
	{
		SetMove(float4::UP);
	}

	if (true == GameEngineInput::GetInst()->IsPress("MoveDown"))
	{
		SetMove(float4::DOWN);
	}
}


void Player::Render()
{

}
