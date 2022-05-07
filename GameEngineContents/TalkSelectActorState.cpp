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
	MyRenderer0_->ChangeAnimation("Booper");	
	MyRenderer1_->Off();
}


void TalkSelectActor::SelectActorStart()
{
	SetPosition({ 640, 620 });
	TalkSelectActorChange(Chapter_);
	MyRenderer1_->On();
	MyRenderer1_->SetPivot({ 0, 50 });
	if (false == GameEngineInput::GetInst()->IsKey("Up"))
	{
		GameEngineInput::GetInst()->CreateKey("Up", 'W');
		GameEngineInput::GetInst()->CreateKey("Down", 'S');
	}
}

void TalkSelectActor::SuccessStart()
{
	SetPosition({ 640, 652 });
	MyRenderer1_->Off();
	MyRenderer0_->ChangeAnimation("Success");
	GameEngineSound::SoundPlayOneShot("Success.wav");
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
	case 4:
		Chapter4Check();
		break;
	case 5:
		Chapter5Check();
		break;
	case 6:
		Chapter6Check();
		break;
	case 7:
		Chapter7Check();
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
		Chapter3Setting();
		break;
	case 4:
		Chapter4Setting();
		break;
	case 5:
		Chapter5Setting();
		break;
	case 6:
		Chapter6Setting();
		break;
	case 7:
		Chapter7Setting();
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
		MyRenderer0_->SetImageAnimationReset("Chapter3_Select0_Selected.bmp");
		MyRenderer1_->SetImage("Chapter3_Select1_UnSelected.bmp");
	}
	else
	{
		MyRenderer0_->SetImageAnimationReset("Chapter3_Select0_UnSelected.bmp");
		MyRenderer1_->SetImage("Chapter3_Select1_Selected.bmp");
	}
}

void TalkSelectActor::Chapter4Setting()
{

	if (Selected0_ == true)
	{
		MyRenderer0_->SetImageAnimationReset("Chapter4_Select0_Selected.bmp");
		MyRenderer1_->SetImage("Chapter4_Select1_UnSelected.bmp");
	}
	else
	{
		MyRenderer0_->SetImageAnimationReset("Chapter4_Select0_UnSelected.bmp");
		MyRenderer1_->SetImage("Chapter4_Select1_Selected.bmp");
	}
}

void TalkSelectActor::Chapter5Setting()
{

	if (Selected0_ == true)
	{
		MyRenderer0_->SetImageAnimationReset("Chapter5_Select0_Selected.bmp");
		MyRenderer1_->SetImage("Chapter5_Select1_UnSelected.bmp");
	}
	else
	{
		MyRenderer0_->SetImageAnimationReset("Chapter5_Select0_UnSelected.bmp");
		MyRenderer1_->SetImage("Chapter5_Select1_Selected.bmp");
	}
}

void TalkSelectActor::Chapter6Setting()
{

	if (Selected0_ == true)
	{
		MyRenderer0_->SetImageAnimationReset("Chapter6_Select0_Selected.bmp");
		MyRenderer1_->SetImage("Chapter6_Select1_UnSelected.bmp");
	}
	else
	{
		MyRenderer0_->SetImageAnimationReset("Chapter6_Select0_UnSelected.bmp");
		MyRenderer1_->SetImage("Chapter6_Select1_Selected.bmp");
	}
}

void TalkSelectActor::Chapter7Setting()
{

	if (Selected0_ == true)
	{
		MyRenderer0_->SetImageAnimationReset("Chapter7_Select0_Selected.bmp");
		MyRenderer1_->SetImage("Chapter7_Select1_UnSelected.bmp");
	}
	else
	{
		MyRenderer0_->SetImageAnimationReset("Chapter7_Select0_UnSelected.bmp");
		MyRenderer1_->SetImage("Chapter7_Select1_Selected.bmp");
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
		ChangeState(TalkSelectActorState::Success);
	}
	else
	{
		GameEngineSound::SoundPlayOneShot("button_dialogue_confirm_01.wav");
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOff();
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
		GameEngineSound::SoundPlayOneShot("button_dialogue_confirm_01.wav");
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOff();
		ChangeState(TalkSelectActorState::Booper);
	}

}

void TalkSelectActor::Chapter3Check()
{
	IsSelect_ = true;
	///////  첫번째 선택지가 정답이다.
	if (Selected0_ == true)
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOn();
		ChangeState(TalkSelectActorState::Success);
	}
	else
	{
		GameEngineSound::SoundPlayOneShot("button_dialogue_confirm_01.wav");
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOff();
		ChangeState(TalkSelectActorState::Booper);
	}

}

void TalkSelectActor::Chapter4Check()
{
	IsSelect_ = true;
	///////  첫번째 선택지가 정답이다.
	if (Selected0_ == true)
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOn();
		ChangeState(TalkSelectActorState::Success);
	}
	else
	{
		GameEngineSound::SoundPlayOneShot("button_dialogue_confirm_01.wav");
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOff();
		ChangeState(TalkSelectActorState::Booper);
	}

}


void TalkSelectActor::Chapter5Check()
{
	IsSelect_ = true;
	///////  첫번째 선택지가 정답이다.
	if (Selected0_ == true)
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOn();
		ChangeState(TalkSelectActorState::Success);
	}
	else
	{
		GameEngineSound::SoundPlayOneShot("button_dialogue_confirm_01.wav");
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOff();
		ChangeState(TalkSelectActorState::Booper);
	}

}


void TalkSelectActor::Chapter6Check()
{
	IsSelect_ = true;
	///////  첫번째 선택지가 정답이다.
	if (Selected0_ == true)
	{
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOn();
		ChangeState(TalkSelectActorState::Success);
	}
	else
	{
		GameEngineSound::SoundPlayOneShot("button_dialogue_confirm_01.wav");
		dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOff();
		ChangeState(TalkSelectActorState::Booper);
	}

}


void TalkSelectActor::Chapter7Check()
{
	IsSelect_ = true;
	///////  두번째 선택지가 정답이다.
	GameEngineSound::SoundPlayOneShot("button_dialogue_confirm_01.wav");
	dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).IsSuccesssOn();
	ChangeState(TalkSelectActorState::Success);
}