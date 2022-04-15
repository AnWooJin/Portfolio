#include "TitleCG.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>

TitleCG::TitleCG()
	:MyRenderer_(nullptr)
{
}

TitleCG::~TitleCG()
{
}

void TitleCG::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	MyRenderer_ = CreateRenderer("TitleCG.bmp", static_cast<int>(EngineMax::RENDERORDERMAX), RenderPivot::CENTER, { 0, -100 });
	MyRenderer_->Off();


}


void TitleCG::Update()
{
	if (TitleLevel::TextPage_ == 1)
	{
		MyRenderer_->On();
	}
}
void TitleCG::Render()
{

}