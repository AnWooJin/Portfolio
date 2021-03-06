#include "TalkText_Chapter8.h"
#include "HellTakerGame.h"
#include "Talk_Chapter8Level.h"
#include "TalkSelectActor_Chapter8.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>

void TalkText_Chapter8::EmptyStart()
{
	SetPosition({ 640, 598 });
	if (MyRenderer_ == nullptr)
	{
		MyRenderer_ = CreateRenderer("Chapter8_TextZERO.bmp");
	}
	else
	{
		MyRenderer_->SetImage("Chapter8_TextZERO.bmp");
	}
}

void TalkText_Chapter8::IdleStart()
{
	if (MyRenderer_ == nullptr)
	{
		MyRenderer_ = CreateRenderer("Chapter8_TalkText_Idle.bmp");
		MyRenderer_->SetIndex(dynamic_cast<Talk_Chapter8Level*>(GetLevel())->GetTextPage());
	}
	else
	{
		MyRenderer_->SetImage("Chapter8_TalkText_Idle.bmp");
		MyRenderer_->SetIndex(dynamic_cast<Talk_Chapter8Level*>(GetLevel())->GetTextPage());
	}
}

void TalkText_Chapter8::Bad0Start()
{
	if (MyRenderer_ == nullptr)
	{
		MyRenderer_ = CreateRenderer("Chapter8_TalkText_Bad00.bmp");
	}
	else
	{
		MyRenderer_->SetImage("Chapter8_TalkText_Bad00.bmp");
	}
}

void TalkText_Chapter8::Bad1Start()
{
	if (MyRenderer_ == nullptr)
	{
		MyRenderer_ = CreateRenderer("Chapter8_TalkText_Bad01.bmp");
	}
	else
	{
		MyRenderer_->SetImage("Chapter8_TalkText_Bad01.bmp");
	}
}

void TalkText_Chapter8::EmptyUpdate()
{
	ChangeTime_ -= GameEngineTime::GetDeltaTime();
	if (ChangeTime_ <= 0.0f)
	{
		ChangeState(TalkText_Chapter8State::Idle);
	}
}

void TalkText_Chapter8::IdleUpdate()
{
	TalkSelectActor_Chapter8* SelectActor = dynamic_cast<TalkSelectActor_Chapter8*>(GetLevel()->FindActor("TalkSelectActor_Chapter8"));
	MyRenderer_->SetIndex(dynamic_cast<Talk_Chapter8Level*>(GetLevel())->GetTextPage());
	if (true == SelectActor->GetIsSelect1() && 
		false == dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).GetIsSuccess())
	{
		ChangeState(TalkText_Chapter8State::Bad1);
	}
	else if (true == SelectActor->GetIsSelect0() && 
		false == dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).GetIsSuccess())
	{
		ChangeState(TalkText_Chapter8State::Bad0);
	}
}

void TalkText_Chapter8::Bad0Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Next"))
	{
		GameEngine::GetInst().ChangeLevel("Death");
	}
}

void TalkText_Chapter8::Bad1Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Next"))
	{
		GameEngine::GetInst().ChangeLevel("Death");
	}
}