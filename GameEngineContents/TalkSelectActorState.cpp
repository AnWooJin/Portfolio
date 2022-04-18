#include "TalkSelectActor.h"
#include "TalkLevel.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineSound.h>

void TalkSelectActor::BooperStart()
{
	SetPosition({ 640, 630 });
	MyRenderer0_ = CreateRenderer();
	MyRenderer0_->CreateAnimation("Booper.bmp", "Booper", 0, 18, 0.1f);
	MyRenderer0_->ChangeAnimation("Booper");
}


void TalkSelectActor::SelectActorStart()
{
	SetPosition({ 640, 580 });
	MyRenderer0_ = CreateRenderer("NewGame_Selected.bmp");
	MyRenderer1_ = CreateRenderer("Exit_UnSelected.bmp");
	MyRenderer1_->SetPivot({ 0, 50 });
	if (false == GameEngineInput::GetInst()->IsKey("Up"))
	{
		GameEngineInput::GetInst()->CreateKey("Up", 'W');
		GameEngineInput::GetInst()->CreateKey("Down", 'S');
	}
}

void TalkSelectActor::BooperUpdate()
{
	if (TalkLevel::TextPage_ == 1)
	{
		MyRenderer0_->Death();
		ChangeState(TalkSelectActorState::SelectActor);
	}
	if (TalkLevel::TextPage_ == 7)
	{
		Death();
	}
}

void TalkSelectActor::SelectActorUpdate()
{
	if (true == GameEngineInput::GetInst()->IsDown("Up"))
	{
		TitleImageChange();
	}
	if (true == GameEngineInput::GetInst()->IsDown("Down"))
	{
		TitleImageChange();
	}
	if (true == GameEngineInput::GetInst()->IsDown("Next") && TalkLevel::TextPage_ == 3)
	{
		if (true == IsSelected_)
		{
			MyRenderer0_->Death();
			MyRenderer1_->Death();
			GameEngineSound::SoundPlayOneShot("button_menu_confirm_01.wav");
			ChangeState(TalkSelectActorState::Booper);
		}
	}
}