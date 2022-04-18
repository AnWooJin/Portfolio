#include "TalkText.h"
#include "TalkLevel.h"
#include "TalkSelectActor.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>

void TalkText::NomalStart()
{
	SetPosition({ 640, 598 });
	if (MyRenderer_ == nullptr)
	{
		MyRenderer_ = CreateRenderer("Chapter1_TalkText.bmp");
	}
	else
	{
		MyRenderer_->SetImage("Chapter1_TalkText.bmp");
	}
}

void TalkText::SuccessStart()
{
	
}

void TalkText::BadStart()
{

}


void TalkText::NomalUpdate()
{
	TalkSelectActor* SelectActor = GetLevel()->FindActor<TalkSelectActor>("TalkSelectActor");

}


void TalkText::SuccessUpdate()
{

}

void TalkText::BadUpdate()
{

}
