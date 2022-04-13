#include "TitleBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImageManager.h>

TitleBackGround::TitleBackGround()
{
}

TitleBackGround::~TitleBackGround()
{
}

void TitleBackGround::Start()
{
	
	
	MyRenderer_ = CreateRenderer("TitleBackGround.bmp");
	MyRenderer_->CameraEffectOn();
	SetPosition(MyRenderer_->GetImage()->GetScale().Half());
}

void TitleBackGround::Render()
{

}