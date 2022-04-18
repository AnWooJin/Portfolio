#include "TitleLevel.h"
#include "TitleSelectActor.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineSound.h>

void TitleSelectActor::BooperStart()
{
	SetPosition({ 640, 630 });
	MyRenderer0_ = CreateRenderer();
	MyRenderer0_->CreateAnimation("Booper.bmp", "Booper", 0, 18, 0.1f);
	MyRenderer0_->ChangeAnimation("Booper");
}


void TitleSelectActor::SelectActorStart()
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

void TitleSelectActor::BooperUpdate()
{
	if (TitleLevel::TextPage_ == 2)
	{
		MyRenderer0_->Death();
		ChangeState(TitleSelectActorState::SelectActor);
	}
	if (TitleLevel::TextPage_ == 7)
	{
		Death();
	}
}

void TitleSelectActor::SelectActorUpdate()
{
	if (true == GameEngineInput::GetInst()->IsDown("Up"))
	{
		TitleImageChange();
	}
	if (true == GameEngineInput::GetInst()->IsDown("Down"))
	{
		TitleImageChange();
	}
	if (true == GameEngineInput::GetInst()->IsDown("Next") && TitleLevel::TextPage_ == 3)
	{
		if (true == IsSelected_)
		{
			MyRenderer0_->Death();
			MyRenderer1_->Death();
			GameEngineSound::SoundPlayOneShot("button_menu_confirm_01.wav");
			ChangeState(TitleSelectActorState::Booper);
		}
	}
}