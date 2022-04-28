#include "Player.h"
#include "HellTakerGame.h"
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

void Player::DeathStart()
{
	BlackBackGround_ = CreateRenderer("BlackBG.bmp",4);
	SetPosition({ GetPosition().x , GetPosition().y - 315.0f });
	BlackBackGround_->SetPivot(GameEngineWindow::GetScale().Half() - GetPosition());
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
	if (true == IsKeyOn_ && true == IsMoveKey())
	{
		if (MoveCount_ == 0)
		{
			ChangeState(PlayerState::Death);
			return;
		}
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

void Player::DeathUpdate()
{
	if (true == MyRenderer_->IsEndAnimation())
	{
		BlackBackGround_->Death();
		GameEngine::GetInst().ChangeLevel("SceneChange");
	}
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
	int Color = ColMapImage_->GetImagePixel(NextPos + GetLevel()->GetCameraPos());
	if (RGB(0, 0, 0) != Color)
	{
		--MoveCount_;
		ChangeAnimation();
		CreateMoveEffect();
		CameraCheck(NextPos);
		KeyCheckTime_ = 0.3f;
	}
}

void Player::CreateMoveEffect()
{
	
	GameEngineActor* Actor = GetLevel()->CreateActor<MoveEffect>(1, "Move");
	Actor->SetPosition(GetPosition() + (float4::DOWN * 5.0f));
	if (8 == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount())
	{
		Actor->SetPosition(GetLevel()->GetCameraPos() + GetPosition() + (float4::DOWN * 5.0f));
	}
}

void Player::ChangeAnimation()
{

	std::string Name = "Player_" + State_ + dir_ ;
	if (CurState_ == PlayerState::Death)
	{
		Name = "Player_" + State_;
	}
	if (nullptr != MyRenderer_->FindAnimation(Name))
	{
		MyRenderer_->ChangeAnimation(Name);
	}	
	else
	{
		return;
	}
}

void Player::CameraCheck(float4 _Pos)
{
	int Chapter = dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount();

	if (Chapter != 8)
	{
		SetPosition(_Pos);
	}
	else if (Chapter == 8)
	{
		Chapter8CameraCheck(_Pos);
	}
}

void Player::Chapter8CameraCheck(float4 _Pos)
{
	float4 CameraPos = GetLevel()->GetCameraPos() + _Pos - GetPosition();
	if (CameraPos.ix() != 0)
	{
		SetPosition(_Pos);
		return;
	}
	else if (CameraPos.iy() > 612 || CameraPos.iy() < 0)
	{
		SetPosition(_Pos);
		return;
	}
	else
	{
		GetLevel()->MoveCameraPos(_Pos - GetPosition());
	}
}
