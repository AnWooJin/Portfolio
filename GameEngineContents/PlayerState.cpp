#include "Player.h"
#include "Key.h"
#include "HellTakerGame.h"
#include "MoveEffect.h"
#include "HugeEffect.h"
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
	Time_ = 0.2f;
	HitCheck_ = false;
	
	if (MyCollision_->CollisionCheck("Thorn") && PrevState_ != PlayerState::Attack)
	{
		GameEngineSound::SoundPlayOneShot("Thorn_Damage.wav");
		MoveCount_--;
		CreateBloodEffect();
		TurnOnRedFilter();
	}
	if (MyCollision_->CollisionCheck("Key"))
	{
		GameEngineSound::SoundPlayOneShot("Key_PickUp.wav");
		CreateHugeEffect();
		HasKey_ = true;
		GetLevel()->FindActor<Key>("Key")->Off();
	}
}

void Player::MoveStart()
{
	if (true == MyFilter_->IsUpdate())
	{
		RedFilterOff();
	}
}

void Player::AttackStart()
{
	HitCheck_ = false;
	IsPlayerMove_ = true;
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

	Time_ -= GameEngineTime::GetDeltaTime();

	FilterTime_ += GameEngineTime::GetDeltaTime() * 4.0f;
	if (FilterTime_ <= 1.0f)
	{
		MyFilter_->SetAlpha(static_cast<unsigned int>(GameEngineMath::LerpLimit(220, 0, FilterTime_)));
		return;
	}
	RedFilterOff();
	if (Time_ >= 0.0f)
	{
		return;
	}
	if (true == MyFilter_->IsUpdate())
	{
		FilterTime_ -= GameEngineTime::GetDeltaTime();
		if (FilterTime_ <= 0.0f)
		{
			RedFilterOff();
		}
	}

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
	if (RGB(0, 0, 255) == Color)
	{
		GameEngine::GetInst().ChangeLevel("Talk");
	}

	else if (RGB(0, 1, 255) == Color)
	{
		GameEngine::GetInst().ChangeLevel("Talk_Chapter8");
	}

	else if (RGB(0, 2, 255) == Color)
	{
		GameEngine::GetInst().ChangeLevel("Epilogue");
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOn();
	}

}

void Player::MoveUpdate()
{
	IsPlayerMove_ = false;
	Time_ += GameEngineTime::GetDeltaTime() * 10.0f;
	if (false == GetPosition().CompareInt2D(EndPos_))
	{
		CameraCheck(float4::LerpLimit(StartPos_, EndPos_, Time_));
		return;
	}
	else if (true == GetPosition().CompareInt2D(EndPos_))
	{
		SetPosition({static_cast<float>(floor(GetPosition().x)), static_cast<float>(floor(GetPosition().y)) });
		ChangeState(PlayerState::Idle);
	}
}

void Player::AttackUpdate()
{
	IsPlayerMove_ = false;
	FilterTime_ += GameEngineTime::GetDeltaTime() * 5.0f;

	if (MyRenderer_->CurrentAnimation()->WorldCurrentFrame() == 0 && false == HitCheck_)
	{
		if (MyCollision_->NextPosCollisionCheck("Thorn", { 0,0 }))
		{
			MoveCount_--;
			CreateBloodEffect();
			TurnOnRedFilter();
			HitCheck_ = true;
		}
	}

	if (FilterTime_ <= 1.0f)
	{
		MyFilter_->SetAlpha(static_cast<unsigned int>(GameEngineMath::LerpLimit(220, 0, FilterTime_)));
		return;
	}

	if (true == MyRenderer_->IsEndAnimation())
	{	
		ChangeState(PlayerState::Idle);
	}
}

void Player::VictoryUpdate()
{
	if (true == MyRenderer_->IsEndAnimation())
	{
		GameEngine::GetInst().ChangeLevel("SceneChange");
	}
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
	std::string  dir;

	if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
	{
		dir = "_Left";
		NextPos += float4::LEFT * 66;
		MovePos = float4::LEFT * 66;
	}

	else if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
	{
		dir = "_Right";
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
		if (dir != "")
		{
			dir_ = dir;
		}
		if (MyCollision_->NextPosCollisionCheck("Skull", MovePos))
		{
			MovePos_ = MovePos;
			GameEngineSound::SoundPlayOneShot("Skull_kick_.wav");
			ChangeState(PlayerState::Attack);
			return false;
		}

		else if (MyCollision_->NextPosCollisionCheck("Block", MovePos))
		{
			MovePos_ = MovePos;
			GameEngineSound::SoundPlayOneShot("Block_Kick.wav");
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
				
				GameEngineSound::SoundPlayOneShot("LockBlock_Kick.wav");
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
		Time_ = 0.0f;
		StartPos_ = GetPosition();
		EndPos_ = GetPosition() + MovePos;
		IsPlayerMove_ = true;
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

void Player::CreateHugeEffect()
{
	GameEngineActor* Actor = GetLevel()->CreateActor<HugeEffect>(7);
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

void Player::TurnOnRedFilter()
{
	std::string Name = "Player_" + State_ + dir_ + "_RedFilter";
	if (nullptr != MyFilter_->FindAnimation(Name))
	{
		MyFilter_->ChangeAnimation(Name);
		MyFilter_->SetAlpha(220);
		FilterTime_ = 0.0f;
	}
	else
	{
		return;
	}

}

void Player::RedFilterOff()
{
	MyFilter_->SetImageAnimationReset("Empty.bmp");
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
