#include "SelectActor.h"
#include "TitleLevel.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>

SelectActor::SelectActor()
	:SelectRenderer0_(nullptr),
	SelectRenderer1_(nullptr),
	IsSelected_(true)
{
}

SelectActor::~SelectActor()
{
}

void SelectActor::Start()
{
	SelectRenderer0_ = CreateRenderer("NewGame_Selected.bmp");
	SelectRenderer1_ = CreateRenderer("Exit_UnSelected.bmp");
	SelectRenderer1_->SetPivot({ 0, 50 });
	SetPosition({ 640, 580 });
	SelectRenderer0_->Off();
	SelectRenderer1_->Off();
	if (false == GameEngineInput::GetInst()->IsKey("Up"))
	{
		GameEngineInput::GetInst()->CreateKey("Up", 'W');
		GameEngineInput::GetInst()->CreateKey("Down", 'S');
	}
}

void SelectActor::Update()
{
	if (TitleLevel::TextPage_ == 2)
	{
		SelectRenderer0_->On();
		SelectRenderer1_->On();
	}

	if (true == GameEngineInput::GetInst()->IsDown("Up"))
	{
		TitleImageChange();
	}
	if (true == GameEngineInput::GetInst()->IsDown("Down"))
	{
		TitleImageChange();
	}
	if(true == GameEngineInput::GetInst()->IsDown("Next") && TitleLevel::TextPage_ == 3)
	{
		if (true == IsSelected_)
		{
			GameEngine::GetInst().ChangeLevel("Prologue");
		}
	}
}


void SelectActor::TitleImageChange()
{
	IsSelected_ = !IsSelected_;
	if (IsSelected_ == true)
	{
		SelectRenderer0_->SetImage("NewGame_Selected.bmp");
		SelectRenderer1_->SetImage("Exit_UnSelected.bmp");
	}
	else
	{
		SelectRenderer0_->SetImage("NewGame_UnSelected.bmp");
		SelectRenderer1_->SetImage("Exit_Selected.bmp");
	}
}