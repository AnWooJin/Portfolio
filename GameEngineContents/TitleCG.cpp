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
	CreateRendererToScale("TitleCG.bmp",{GameEngineWindow::GetScale().x, 500}, RenderPivot::CENTER, {0, -100});
}

void TitleCG::Render()
{

}