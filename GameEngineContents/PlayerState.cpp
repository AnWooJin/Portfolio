#include "Player.h"
#include "HellTakerGame.h"
#include "MoveEffect.h"
#include "HitEffect.h"
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
	BlackBackGround_ = CreateRenderer("BlackBG.bmp",4);
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
	if (RGB(0, 0, 255) == Color)
	{
		GameEngine::GetInst().ChangeLevel("Talk");
	}
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
	if (false == IsMoveKey())
	{
		ChangeState(PlayerState::Idle);
	}
	if (true == IsMoveKey())
	{
		PlayerMove();
	}	

}

void Player::AttackUpdate()
{
	if (true == MyRenderer_->IsEndAnimation())
	{
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


void Player::PlayerMove()
{
	if (Time_ >= 0.0f)
	{
		return;
	}
	float4 NextPos = GetPosition();
	float4 MovePos = float4::ZERO;

	if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
	{
		dir_ = "_Left";
		NextPos += float4::LEFT * 66;
		MovePos = float4::LEFT * 66;
		IsKeyOn_ = false;
	}

	else if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
	{
		dir_ = "_Right";
		NextPos += float4::RIGHT * 66;
		MovePos = float4::RIGHT * 66;
		IsKeyOn_ = false;
	}

	else if (true == GameEngineInput::GetInst()->IsPress("MoveUp"))
	{
		NextPos += float4::UP * 65;
		MovePos = float4::UP * 65;
		IsKeyOn_ = false;
	}

	else if (true == GameEngineInput::GetInst()->IsPress("MoveDown"))
	{
		NextPos += float4::DOWN * 65;
		MovePos = float4::DOWN * 65;
		IsKeyOn_ = false;
	}
	
	int Color = ColMapImage_->GetImagePixel(NextPos);

	if (RGB(0, 0, 0) != Color)
	{
		ChangeAnimation();
		--MoveCount_;
		if (MyCollision_->NextPosCollisionCheck("Skull", MovePos))
		{
			GameEngineSound::SoundPlayOneShot("Skull_kick_.wav");
			MovePos_ = MovePos;
			ChangeState(PlayerState::Attack);
			return;
		}

		else if (MyCollision_->NextPosCollisionCheck("Block", MovePos))
		{
			GameEngineSound::SoundPlayOneShot("Skull_kick_.wav");
			CreateHitEffect(MovePos);
			MovePos_ = MovePos;
			ChangeState(PlayerState::Attack);
			return;
		}

		else if (MyCollision_->NextPosCollisionCheck("LockBlock", MovePos))
		{
			MovePos_ = MovePos;
			if (false == HasKey_)
			{
				GameEngineSound::SoundPlayOneShot("Skull_kick_.wav");
				ChangeState(PlayerState::Attack);
				CreateHitEffect(MovePos);
				return;
			}
			else if (true == HasKey_)
			{
				MyCollision_->NextPosCollisionCheck("LockBlock", { 0,0 });
			}
		}

		GameEngineSound::SoundPlayOneShot("Player_Move.wav");
		CreateMoveEffect();
		CameraCheck(NextPos);
		if (MyCollision_->CollisionCheck("Thron"))
		{
			MoveCount_--;
			CreateBloodEffect();
		}
		KeyCheckTime_ = 0.1f;
	}
	
	else
	{
		ChangeState(PlayerState::Idle);
	}
	Time_ = 0.3f;
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

}

void Player::CreateHitEffect(float4 _Pos)
{

	GameEngineActor* Actor = GetLevel()->CreateActor<HitEffect>(6, "Hit");
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
