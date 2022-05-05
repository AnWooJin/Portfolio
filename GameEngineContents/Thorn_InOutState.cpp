#include "Thorn_InOut.h"
#include "Player.h"
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineCollision.h>


void Thorn_InOut::InStart()
{
	MyRenderer_->ChangeAnimation("Thorn_In");
	MyCollision_->Off();
}

void Thorn_InOut::OutStart()
{
	MyRenderer_->ChangeAnimation("Thorn_Out");
	MyCollision_->On();
}

void Thorn_InOut::InUpdate()
{
	if (MoveCount_ != MyPlayer_->GetMoveCount())
	{
		ChangeState(Thorn_InOutState::Out);
		MoveCount_ = MyPlayer_->GetMoveCount();
	}
}

void Thorn_InOut::OutUpdate()
{
	if (MoveCount_ != MyPlayer_->GetMoveCount())
	{
		ChangeState(Thorn_InOutState::In);
		MoveCount_ = MyPlayer_->GetMoveCount();
	}
}