#include "TalkLevel.h"
#include "TalkBackGround.h"
#include "TalkCG.h"
#include "TalkSelectActor.h"
#include "TalkText.h"
#include <GameEngineBase/GameEngineInput.h>



TalkLevel::TalkLevel()
	:TextPage_(0)
{
}

TalkLevel::~TalkLevel()
{
}

void TalkLevel::Loading()
{
	if (false == GameEngineInput::GetInst()->IsKey("Next"))
	{
		GameEngineInput::GetInst()->CreateKey("Next", VK_SPACE);
	}

	CreateActor<TalkSelectActor>(4);
	CreateActor<TalkBackGround>(1);
	CreateActor<TalkCG>(2);
	CreateActor<TalkText>(3);
	
}

void TalkLevel::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Next") && TextPage_ <= 2)
	{
		++TextPage_;
		GameEngineSound::SoundPlayOneShot("dialogue_text_end_01.wav");
	}
}

void TalkLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	TextPage_ = 0;
}

void TalkLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}
