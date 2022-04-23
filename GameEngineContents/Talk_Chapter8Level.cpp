#include <GameEngineBase/GameEngineInput.h>
#include "Talk_Chapter8Level.h"
#include "TalkCG_Chapter8.h"
#include "TalkSelectActor_Chapter8.h"
#include "TalkText_Chapter8.h"

Talk_Chapter8Level::Talk_Chapter8Level()
	: SelectActorCall_(false),
	  TextPage_(0)
{
}

Talk_Chapter8Level::~Talk_Chapter8Level()
{
}


void Talk_Chapter8Level::Loading()
{
	if (false == GameEngineInput::GetInst()->IsKey("Next"))
	{
		GameEngineInput::GetInst()->CreateKey("Next", VK_SPACE);
	}
	
	CreateActor<TalkSelectActor_Chapter8>(4);
	CreateActor<TalkCG_Chapter8>(3);
	CreateActor<TalkText_Chapter8>(3);
}

void Talk_Chapter8Level::Update()
{
	
	if (true == GameEngineInput::GetInst()->IsDown("Next") && false == SelectActorCall_)
	{
		GameEngineSound::SoundPlayOneShot("dialogue_text_end_01.wav");

		if (TextPage_ == 1 || TextPage_ == 3)
		{
			SelectActorCallOn();
			return;
		}	
		++TextPage_;
	}
}

void Talk_Chapter8Level::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}

void Talk_Chapter8Level::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}
