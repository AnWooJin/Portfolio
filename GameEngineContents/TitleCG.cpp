#include "TitleCG.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
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
	MyRenderer_ = CreateRenderer("TitleCG.bmp", static_cast<int>(EngineMax::RENDERORDERMAX), RenderPivot::CENTER, {0, -100});
	MyRenderer_->Off();
	
	if (false == GameEngineInput::GetInst()->IsKey("Change"))
	{
		GameEngineInput::GetInst()->CreateKey("Change", 'T');
	}
}


void TitleCG::Update()
{
	if (true == GameEngineInput::GetInst()->IsPress("Change"))
	{
		MyRenderer_->On();
	}
}
void TitleCG::Render()
{

}