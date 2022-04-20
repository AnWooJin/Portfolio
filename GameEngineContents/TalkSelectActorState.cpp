#include "TalkSelectActor.h"
#include "HellTakerGame.h"
#include "TalkLevel.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineSound.h>

void TalkSelectActor::BooperStart()
{
	SetPosition({ 640, 630 });
	if (MyRenderer0_ == nullptr)
	{
		MyRenderer0_ = CreateRenderer();
		MyRenderer1_ = CreateRenderer();
	}
	MyRenderer1_->Off();
	MyRenderer0_->CreateAnimation("Booper.bmp", "Booper", 0, 18, 0.1f);
	MyRenderer0_->ChangeAnimation("Booper");
}


void TalkSelectActor::SelectActorStart()
{
	MyRenderer1_->On();
	MyRenderer0_ = CreateRenderer();
	SetPosition({ 640, 620 });
	Chapter1Setting();
	MyRenderer1_->SetPivot({ 0, 50 });
	if (false == GameEngineInput::GetInst()->IsKey("Up"))
	{
		GameEngineInput::GetInst()->CreateKey("Up", 'W');
		GameEngineInput::GetInst()->CreateKey("Down", 'S');
	}
}

void TalkSelectActor::BooperUpdate()
{
	if (dynamic_cast<TalkLevel*>(GetLevel())->GetTextPage() == 1)
	{
		MyRenderer0_->Death();
		ChangeState(TalkSelectActorState::SelectActor);
	}
}

void TalkSelectActor::SelectActorUpdate()
{
	if (true == GameEngineInput::GetInst()->IsDown("Up"))
	{
		GameEngineSound::SoundPlayOneShot("button_menu_highlight_01.wav");
		Selected0_ = !Selected0_;
		TalkSelectActorChange(Chapter_);
	}
	if (true == GameEngineInput::GetInst()->IsDown("Down"))
	{
		GameEngineSound::SoundPlayOneShot("button_menu_highlight_01.wav");
		Selected0_ = !Selected0_;
		TalkSelectActorChange(Chapter_);
	}
	if (true == GameEngineInput::GetInst()->IsDown("Next") && dynamic_cast<TalkLevel*>(GetLevel())->GetTextPage() == 2)
	{
		TalkSuccessCheck(Chapter_);
	}
}

void TalkSelectActor::TalkSuccessCheck(int _Chapter)
{
	switch (_Chapter)
	{
	case 1:
		Chapter1Check();
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}

void TalkSelectActor::TalkSelectActorChange(int _Chapter)
{
	switch (_Chapter)
	{
	case 1:
		Chapter1Setting();
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}


///////////////////////////////////    챕터별로 SelectActor이미지를 세팅해주는 함수

void TalkSelectActor::Chapter1Setting()
{
	
	if (Selected0_ == true)
	{
		MyRenderer0_->SetImage("Chapter1_Select0_Selected.bmp");
		MyRenderer1_->SetImage("Chapter1_Select1_UnSelected.bmp");
	}
	else
	{
		MyRenderer0_->SetImage("Chapter1_Select0_UnSelected.bmp");
		MyRenderer1_->SetImage("Chapter1_Select1_Selected.bmp");
	}
}


/////////////////////////////////////    챕터별로 성공여부를 판단하는 함수

void TalkSelectActor::Chapter1Check()
{
	IsSelect_ = true;
	///////  두번째 선택지가 정답이다.
	if (Selected0_ == false)
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssTrue();
		ChangeState(TalkSelectActorState::Booper);
	}
	else
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssfalse();
		ChangeState(TalkSelectActorState::Booper);
	}
	
}