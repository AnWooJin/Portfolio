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
	}
	MyRenderer0_->CreateAnimation("Booper.bmp", "Booper", 0, 18, 0.1f);
	MyRenderer0_->ChangeAnimation("Booper");	
}


void TalkSelectActor::SelectActorStart()
{
	if (MyRenderer1_ == nullptr)
	{
		MyRenderer1_ = CreateRenderer();
	}
	SetPosition({ 640, 620 });
	TalkSelectActorChange(Chapter_);
	MyRenderer1_->SetPivot({ 0, 50 });
	if (false == GameEngineInput::GetInst()->IsKey("Up"))
	{
		GameEngineInput::GetInst()->CreateKey("Up", 'W');
		GameEngineInput::GetInst()->CreateKey("Down", 'S');
	}
}

void TalkSelectActor::SuccessStart()
{

}

void TalkSelectActor::BooperUpdate()
{
	if (dynamic_cast<TalkLevel*>(GetLevel())->GetTextPage() == 1)
	{
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

void TalkSelectActor::SuccessUpdate()
{

}

void TalkSelectActor::TalkSuccessCheck(int _Chapter)
{
	switch (_Chapter)
	{
	case 1:
		Chapter1Check();
		break;
	case 2:
		Chapter2Check();
		break;
	case 3:
		Chapter3Check();
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
		Chapter2Setting();
		break;
	case 3:
		Chapter2Setting();
		break;
	case 4:
		Chapter2Setting();
		break;
	case 5:
		Chapter2Setting();
	case 6:
		Chapter2Setting();
		break;
	case 7:
		Chapter2Setting();
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
		MyRenderer0_->SetImageAnimationReset("Chapter1_Select0_Selected.bmp");
		MyRenderer1_->SetImage("Chapter1_Select1_UnSelected.bmp");
	}
	else
	{
		MyRenderer0_->SetImageAnimationReset("Chapter1_Select0_UnSelected.bmp");
		MyRenderer1_->SetImage("Chapter1_Select1_Selected.bmp");
	}
}

void TalkSelectActor::Chapter2Setting()
{

	if (Selected0_ == true)
	{
		MyRenderer0_->SetImageAnimationReset("Chapter2_Select0_Selected.bmp");
		MyRenderer1_->SetImage("Chapter2_Select1_UnSelected.bmp");
	}
	else
	{
		MyRenderer0_->SetImageAnimationReset("Chapter2_Select0_UnSelected.bmp");
		MyRenderer1_->SetImage("Chapter2_Select1_Selected.bmp");
	}
}

void TalkSelectActor::Chapter3Setting()
{

	if (Selected0_ == true)
	{
		MyRenderer0_->SetImageAnimationReset("Chapter2_Select0_Selected.bmp");
		MyRenderer1_->SetImage("Chapter2_Select1_UnSelected.bmp");
	}
	else
	{
		MyRenderer0_->SetImageAnimationReset("Chapter2_Select0_UnSelected.bmp");
		MyRenderer1_->SetImage("Chapter2_Select1_Selected.bmp");
	}
}



/////////////////////////////////////    챕터별로 성공여부를 판단하는 함수

void TalkSelectActor::Chapter1Check()
{
	IsSelect_ = true;
	///////  두번째 선택지가 정답이다.
	if (Selected0_ == false)
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOn();
		MyRenderer0_->Death();
		MyRenderer1_->Death();
		MyRenderer0_ = nullptr;
		MyRenderer1_ = nullptr;
		ChangeState(TalkSelectActorState::Booper);
	}
	else
	{
		//dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOff();
		ChangeState(TalkSelectActorState::Booper);
	}
	
}

void TalkSelectActor::Chapter2Check()
{
	IsSelect_ = true;
	///////  두번째 선택지가 정답이다.
	if (Selected0_ == false)
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOn();
		ChangeState(TalkSelectActorState::Success);
	}
	else
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOff();
		ChangeState(TalkSelectActorState::Booper);
	}

}

void TalkSelectActor::Chapter3Check()
{
	IsSelect_ = true;
	///////  두번째 선택지가 정답이다.
	if (Selected0_ == false)
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOn();
		ChangeState(TalkSelectActorState::Booper);
	}
	else
	{
		//dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOff();
		ChangeState(TalkSelectActorState::Booper);
	}

}