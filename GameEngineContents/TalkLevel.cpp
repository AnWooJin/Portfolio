#include "TalkLevel.h"
#include "TalkBackGround.h"
#include "TalkCG.h"
#include "TalkSelectActor.h"
#include "TalkText.h"

int TalkLevel::TextPage_ = 0;

TalkLevel::TalkLevel()
{
}

TalkLevel::~TalkLevel()
{
}

void TalkLevel::Loading()
{
	CreateActor<TalkBackGround>(1);
	CreateActor<TalkCG>(2);
	CreateActor<TalkText>(3);
	CreateActor<TalkSelectActor>(4);
}

void TalkLevel::Update()
{

}

void TalkLevel::LevelChangeStart()
{

}

void TalkLevel::LevelChangeEnd()
{

}
