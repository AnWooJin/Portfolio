#include <GameEngineBase/GameEngineInput.h>
#include "Talk_Chapter8Level.h"
#include "TalkBackGround_Chapter8.h"
#include "TalkCG_Chapter8.h"
#include "TalkExtraCG_Chapter8.h"
#include "TalkSelectActor_Chapter8.h"
#include "TalkText_Chapter8.h"

Talk_Chapter8Level::Talk_Chapter8Level()
{
}

Talk_Chapter8Level::~Talk_Chapter8Level()
{
}


void Talk_Chapter8Level::Loading()
{
	//CreateActor<TalkExtraCG_Chapter8>(1)->SetPosition({ 1280, 250 });;
	


	CreateActor<TalkSelectActor_Chapter8>(4);
	CreateActor<TalkBackGround_Chapter8>(1);
	CreateActor<TalkCG_Chapter8>(3);
	//CreateActor<TalkText_Chapter8>(3);
}

void Talk_Chapter8Level::Update()
{

}

void Talk_Chapter8Level::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}

void Talk_Chapter8Level::LevelChangeEnd(GameEngineLevel* _NextLevel)
{

}
