#include "TitleCG.h"

#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>

TitleCG::TitleCG()
{
}

TitleCG::~TitleCG()
{
}

void TitleCG::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	CreateRenderer("TitleCG.bmp", static_cast<int>(EngineMax::RENDERORDERMAX), RenderPivot::CENTER, {0, -100});
}

void TitleCG::Render()
{

}