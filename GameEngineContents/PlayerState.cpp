#include "Player.h"
#include "MoveEffect.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>


void Player::IdleStart()
{

}

void Player::MoveStart()
{

}

void Player::AttackStart()
{

}


void Player::VictoryStart()
{

}

void Player::IdleUpdate()
{
	if (true == IsMoveKey() && true == IsKeyOn_)
	{
		ChangeState(PlayerState::Move);
	}
	if (true == GameEngineInput::GetInst()->IsPress("Die"))
	{
		GameEngine::GetInst().ChangeLevel("SceneChange");
	}
}

void Player::MoveUpdate()
{
	if (true == IsKeyOn_)
	{
		PlayerMove();
	}
	if (false == IsMoveKey())
	{
		ChangeState(PlayerState::Idle);
	}
}

void Player::AttackUpdate()
{

}

void Player::VictoryUpdate()
{

}


void Player::PlayerMove()
{
	float4 NextPos = GetPosition();

	if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
	{
		dir_ = "_Left";
		NextPos += float4::LEFT * 66;
		IsKeyOn_ = false;
	}

	else if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
	{
		dir_ = "_Right";
		NextPos += float4::RIGHT * 66;
		IsKeyOn_ = false;
	}

	else if (true == GameEngineInput::GetInst()->IsPress("MoveUp"))
	{
		NextPos += float4::UP * 65;
		IsKeyOn_ = false;
	}

	else if (true == GameEngineInput::GetInst()->IsPress("MoveDown"))
	{
		NextPos += float4::DOWN * 65;
		IsKeyOn_ = false;
	}
	int Color = ColMapImage_->GetImagePixel(NextPos);
	if (RGB(0, 0, 0) != Color)
	{
		ChangeAnimation();
		CreateMoveEffect();
		SetPosition(NextPos);
		KeyCheckTime_ = 0.15f;
	}
}

void Player::CreateMoveEffect()
{
	GameEngineActor* Actor = GetLevel()->CreateActor<MoveEffect>(1, "Move");
	Actor->SetPosition(GetPosition() + (float4::DOWN * 5.0f));
}

void Player::ChangeAnimation()
{

	std::string Name = "Player_" + State_ + dir_ ;
	if (nullptr != MyRenderer_->FindAnimation(Name))
	{
		MyRenderer_->ChangeAnimation(Name);
	}	
	else
	{
		return;
	}
}


