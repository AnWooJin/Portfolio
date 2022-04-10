#include "TitleCG.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>

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

	if (false == GameEngineInput::GetInst()->IsKey("Change"))
	{
		GameEngineInput::GetInst()->CreateKey("Change", 'T');
	}
}


void TitleCG::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Change"))
	{
		GameEngine::GetInst().ChangeLevel("Chapter1Level");
		/*MyRender_->ChangeAnimation("Player_Victory");
		NextPos = GetPosition() + (float4::UP * 6);*/
	}
}
void TitleCG::Render()
{

}