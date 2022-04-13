#include "OpeningBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>

OpeningBackGround::OpeningBackGround()
	: OpeningBackGroundRenderer_(nullptr)
{
}

OpeningBackGround::~OpeningBackGround()
{
}

void OpeningBackGround::Start()
{
	SetPosition(GameEngineWindow::GetInst().GetScale().Half());
	OpeningBackGroundRenderer_ = CreateRenderer("OpeningBackGround.bmp");
}

void OpeningBackGround::Update()
{

}