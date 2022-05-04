#include "Player.h"
#include "HellTakerGame.h"
#include "MoveEffect.h"
#include "HitEffect.h"
#include "BloodEffect.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngine/GameEngineCollision.h>
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
	GameEngineSound::SoundPlayOneShot("Player_Death.wav");
	BlackBackGround_ = CreateRenderer("BlackBG.bmp",5);
	SetPosition({ GetPosition().x , GetPosition().y - 315.0f });
	BlackBackGround_->SetPivot(GameEngineWindow::GetScale().Half() - GetPosition());
}

void Player::IdleUpdate()
{
	if (true == dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).GetIsSuccess())
	{
		ChangeState(PlayerState::Victory);
		return;
	}
	else if (MoveCount_ == 0 && true == IsMoveKey())
	{
		ChangeState(PlayerState::Death);
		return;
	}
	int Color = ColMapImage_->GetImagePixel(GetPosition() + GetLevel()->GetCameraPos());
	
	if (true == IsMoveKey())
	{
		if (true == PlayerMove())
		{
			ChangeState(PlayerState::Move);
		}
	}
	else if (true == GameEngineInput::GetInst()->IsPress("Die"))
	{
		GameEngine::GetInst().ChangeLevel("SceneChange");
	}
	if (RGB(0, 0, 255) == Color)
	{
		GameEngine::GetInst().ChangeLevel("Talk");
	}

}

void Player::MoveUpdate()
{
	Time_ += GameEngineTime::GetDeltaTime() * 5.0f;
	if (false == GetPosition().CompareInt2D(EndPos_))
	{
		CameraCheck(float4::LerpLimit(StartPos_, EndPos_, Time_));
		return;
	}
	else if (true == GetPosition().CompareInt2D(EndPos_))
	{
		SetPosition({static_cast<float>(floor(GetPosition().x)), static_cast<float>(floor(GetPosition().y)) });
		if (MyCollision_->CollisionCheck("Thorn"))
		{
			MoveCount_--;
			CreateBloodEffect();
		}

		else if (MyCollision_->CollisionCheck("Key"))
		{
			HasKey_ = true;
		}
		ChangeState(PlayerState::Idle);
	}
}

void Player::AttackUpdate()
{
	if (true == MyRenderer_->IsEndAnimation())
	{
		if (MyCollision_->NextPosCollisionCheck("Thorn", {0,0}))
		{
			MoveCount_--;
			CreateBloodEffect();
		}
		ChangeState(PlayerState::Idle);
	}
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


bool Player::PlayerMove()
{
	float4 NextPos = GetPosition();
	float4 MovePos = float4::ZERO;

	if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
	{
		dir_ = "_Left";
		NextPos += float4::LEFT * 66;
		MovePos = float4::LEFT * 66;
	}

	else if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
	{
		dir_ = "_Right";
		NextPos += float4::RIGHT * 66;
		MovePos = float4::RIGHT * 66;
	}

	else if (true == GameEngineInput::GetInst()->IsPress("MoveUp"))
	{
		NextPos += float4::UP * 65;
		MovePos = float4::UP * 65;
	}

	else if (true == GameEngineInput::GetInst()->IsPress("MoveDown"))
	{
		NextPos += float4::DOWN * 65;
		MovePos = float4::DOWN * 65;
	}
	
	int Color = ColMapImage_->GetImagePixel(NextPos);

	if (RGB(0, 0, 0) != Color)
	{
		--MoveCount_;
		if (MyCollision_->NextPosCollisionCheck("Skull", MovePos))
		{
			GameEngineSound::SoundPlayOneShot("Skull_kick_.wav");
			ChangeState(PlayerState::Attack);
			return false;
		}

		else if (MyCollision_->NextPosCollisionCheck("Block", MovePos))
		{
			GameEngineSound::SoundPlayOneShot("Skull_kick_.wav");
			CreateHitEffect(MovePos);
			MovePos_ = MovePos;
			ChangeState(PlayerState::Attack);
			return false;
		}

		else if (MyCollision_->NextPosCollisionCheck("LockBlock", MovePos))
		{
			MovePos_ = MovePos;
			if (false == HasKey_)
			{
				GameEngineSound::SoundPlayOneShot("Skull_kick_.wav");
				ChangeState(PlayerState::Attack);
				CreateHitEffect(MovePos);
				return false;
			}
			else if (true == HasKey_)
			{
				MyCollision_->NextPosCollisionCheck("LockBlock", { 0,0 });
			}
		}

		GameEngineSound::SoundPlayOneShot("Player_Move.wav");
		CreateMoveEffect();
		StartPos_ = GetPosition();
		EndPos_ = GetPosition() + MovePos;
		Time_ = 0.0f;
		return true;
	}
	else
	{
		return false;
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

void Player::CreateBloodEffect()
{
	GameEngineActor* Actor = GetLevel()->CreateActor<BloodEffect>(7);
	Actor->SetPosition(GetPosition());
}

void Player::CreateHitEffect(float4 _Pos)
{

	GameEngineActor* Actor = GetLevel()->CreateActor<HitEffect>(7, "Hit");
	Actor->SetPosition(GetPosition() + _Pos);
	if (8 == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount())
	{
		Actor->SetPosition(GetLevel()->GetCameraPos() + GetPosition());
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
		SetPosition(_Pos);
	}
}
