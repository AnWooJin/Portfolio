#include "BlackBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>

BlackBackGround::BlackBackGround()
{
}

BlackBackGround::~BlackBackGround()
{
}

void BlackBackGround::Start()
{
	CreateRenderer("BlackBG.bmp");
	SetPosition(GameEngineWindow::GetScale().Half());
	
}