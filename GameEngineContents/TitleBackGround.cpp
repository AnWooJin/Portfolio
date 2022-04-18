#include "TitleBackGround.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImageManager.h>

TitleBackGround::TitleBackGround()
	: MyRenderer_(nullptr)
{
}

TitleBackGround::~TitleBackGround()
{
}

void TitleBackGround::Start()
{
	MyRenderer_ = CreateRenderer("TitleBackGround.bmp");
	MyRenderer_->CameraEffectOn();
	SetPosition(MyRenderer_->GetImage()->GetScale().Half() + (float4::DOWN * 100));
}

void TitleBackGround::Update()
{

}

void TitleBackGround::Render()
{

}