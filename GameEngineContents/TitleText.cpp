#include "TitleText.h"
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>

TitleText::TitleText()
	: MyRenderer_(nullptr)
{
}

TitleText::~TitleText()
{
}

void TitleText::Start()
{
	SetPosition({640, 598});
	MyRenderer_ = CreateRenderer("TitleText00.bmp");
}

void TitleText::Update()
{

}