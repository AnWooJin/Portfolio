#include "SelectActor.h"
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>

SelectActor::SelectActor()
{
}

SelectActor::~SelectActor()
{
}

void SelectActor::Start()
{
	MyRenderer_ = CreateRenderer("NewGame_Selected.bmp");
	SetPosition({ 640, 690 });

	if (false == GameEngineInput::GetInst()->IsKey("Up"))
	{
		GameEngineInput::GetInst()->CreateKey("Up", 'W');
		GameEngineInput::GetInst()->CreateKey("Down", 'S');
	}
}

void SelectActor::Update()
{
	if (true == GameEngineInput::GetInst()->IsPress("Up"))
	{
		MyRenderer_->SetImage("NewGame_UnSelected.bmp");
	}
}