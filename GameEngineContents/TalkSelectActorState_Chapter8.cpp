#include "TalkSelectActor_Chapter8.h"
#include "HellTakerGame.h"
#include "Talk_Chapter8Level.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineSound.h>

void TalkSelectActor_Chapter8::EmptyStart()
{

}
void TalkSelectActor_Chapter8::BooperStart()
{
	SetPosition({ 640, 630 });
	if (false == MyRenderer0_->IsUpdate())
	{
		MyRenderer0_->On();
	}
	MyRenderer0_->ChangeAnimation("Booper");

}

void TalkSelectActor_Chapter8::SelectActorStart()
{
	dynamic_cast<Talk_Chapter8Level*>(GetLevel())->SelectActorCallOn();
	MyRenderer1_->On();
	SetPosition({ 640, 620 });
	MyRenderer1_->SetPivot({ 0, 50 });
	TalkSelectActorChange();
	if (false == GameEngineInput::GetInst()->IsKey("Up"))
	{
		GameEngineInput::GetInst()->CreateKey("Up", 'W');
		GameEngineInput::GetInst()->CreateKey("Down", 'S');
	}
}

void TalkSelectActor_Chapter8::SuccessStart()
{
	SetPosition({ 640, 640 });
	MyRenderer0_->ChangeAnimation("Success");
	GameEngineSound::SoundPlayOneShot("Success.wav");
}

void TalkSelectActor_Chapter8::EmptyUpdate()
{
	ChangeTime_ -= GameEngineTime::GetDeltaTime();
	if (ChangeTime_ <= 0.0f)
	{
		ChangeState(TalkSelectActor_Chapter8State::Booper);
	}
}

void TalkSelectActor_Chapter8::BooperUpdate()
{
	if (true == dynamic_cast<Talk_Chapter8Level*>(GetLevel())->GetSelectActorCall())
	{
		ChangeState(TalkSelectActor_Chapter8State::SelectActor);
	}

}

void TalkSelectActor_Chapter8::SelectActorUpdate()
{
	if (true == GameEngineInput::GetInst()->IsDown("Up"))
	{
		Selected0_ = !Selected0_;
		TalkSelectActorChange();
		GameEngineSound::SoundPlayOneShot("button_menu_highlight_01.wav");
	
	}
	if (true == GameEngineInput::GetInst()->IsDown("Down"))
	{
		Selected0_ = !Selected0_;
		TalkSelectActorChange();
		GameEngineSound::SoundPlayOneShot("button_menu_highlight_01.wav");	
	}

	if (true == GameEngineInput::GetInst()->IsDown("Next"))
	{	
		GameEngineSound::SoundPlayOneShot("button_dialogue_confirm_01.wav");
		GameEngineSound::SoundPlayOneShot("dialogue_text_end_01.wav");
		TalkSuccessCheck();
	}
}
 //TextPage = 5
void TalkSelectActor_Chapter8::SuccessUpdate()
{
	if (true == GameEngineInput::GetInst()->IsDown("Next"))
	{
		ChangeState(TalkSelectActor_Chapter8State::Booper);
	}
}
void TalkSelectActor_Chapter8::TalkSuccessCheck()
{
	switch (SelectActorSetNum_)
	{
	case 0:
		Select0Check();
		break;
	case 1:
		Select1Check();
		break;
	default:
		break;
	}
}
void TalkSelectActor_Chapter8::TalkSelectActorChange()
{
	switch (SelectActorSetNum_)
	{
	case 0:
		Select0Setting();
		break;
	case 1:
		Select1Setting();
		break;
	default:
		break;
	}
}



void TalkSelectActor_Chapter8::Select0Check()
{
	IsSelect0_ = true;
	MyRenderer1_->Off();
	SelectActorSetNum_ = 1;
	dynamic_cast<Talk_Chapter8Level*>(GetLevel())->SelectActorCallOff();
	///////  두번째 선택지가 정답이다.
	if (Selected0_ == false)
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOn();
	}
	else
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOff();
	}
	ChangeState(TalkSelectActor_Chapter8State::Booper);
}

void TalkSelectActor_Chapter8::Select1Check()
{
	IsSelect1_ = true;
	MyRenderer1_->Off();
	dynamic_cast<Talk_Chapter8Level*>(GetLevel())->SelectActorCallOff();
	///////  두번째 선택지가 정답이다.
	if (Selected0_ == false)
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOn();
		ChangeState(TalkSelectActor_Chapter8State::Success);
	}
	else
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOff();
		ChangeState(TalkSelectActor_Chapter8State::Booper);
	}
}


void TalkSelectActor_Chapter8::Select0Setting()
{

	if (Selected0_ == true)
	{
		MyRenderer0_->SetImageAnimationReset("Chapter8_0_Select0_Selected.bmp");
		MyRenderer1_->SetImage("Chapter8_0_Select1_UnSelected.bmp");
	}
	else
	{
		MyRenderer0_->SetImageAnimationReset("Chapter8_0_Select0_UnSelected.bmp");
		MyRenderer1_->SetImage("Chapter8_0_Select1_Selected.bmp");
	}
}

void TalkSelectActor_Chapter8::Select1Setting()
{

	if (Selected0_ == true)
	{
		MyRenderer0_->SetImageAnimationReset("Chapter8_1_Select0_Selected.bmp");
		MyRenderer1_->SetImage("Chapter8_1_Select1_UnSelected.bmp");
	}
	else
	{
		MyRenderer0_->SetImageAnimationReset("Chapter8_1_Select0_UnSelected.bmp");
		MyRenderer1_->SetImage("Chapter8_1_Select1_Selected.bmp");
	}
}