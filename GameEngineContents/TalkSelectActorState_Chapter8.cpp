#include "TalkSelectActor_Chapter8.h"
#include "HellTakerGame.h"
#include "TalkLevel.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineSound.h>

void TalkSelectActor_Chapter8::BooperStart()
{
	SetPosition({ 640, 630 });
	if (MyRenderer0_ == nullptr)
	{
		MyRenderer0_ = CreateRenderer();
	}
	MyRenderer0_->CreateAnimation("Booper.bmp", "Booper", 0, 18, 0.1f);
	MyRenderer0_->ChangeAnimation("Booper");
}

void TalkSelectActor_Chapter8::SelectActorStart()
{
	if (MyRenderer1_ == nullptr)
	{
		MyRenderer1_ = CreateRenderer();
	}
	SetPosition({ 640, 620 });
	MyRenderer1_->SetPivot({ 0, 50 });
	if (false == GameEngineInput::GetInst()->IsKey("Up"))
	{
		GameEngineInput::GetInst()->CreateKey("Up", 'W');
		GameEngineInput::GetInst()->CreateKey("Down", 'S');
	}
}

void TalkSelectActor_Chapter8::SuccessStart()
{

}

void TalkSelectActor_Chapter8::BooperUpdate()
{
	
}

void TalkSelectActor_Chapter8::SelectActorUpdate()
{
	if (true == GameEngineInput::GetInst()->IsDown("Up"))
	{
		GameEngineSound::SoundPlayOneShot("button_menu_highlight_01.wav");
		Selected0_ = !Selected0_;
	}
	if (true == GameEngineInput::GetInst()->IsDown("Down"))
	{
		GameEngineSound::SoundPlayOneShot("button_menu_highlight_01.wav");
		Selected0_ = !Selected0_;
	}
	if (true == GameEngineInput::GetInst()->IsDown("Next") && dynamic_cast<TalkLevel*>(GetLevel())->GetTextPage() == 2)
	{

	}
}

void TalkSelectActor_Chapter8::SuccessUpdate()
{

}