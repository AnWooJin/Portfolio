#include "UnityLogo.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>

UnityLogo::UnityLogo()
	: UnityRenderer_(nullptr)
	, Alpha_(255)
	, AlphaTime_(0.008f)
{
}

UnityLogo::~UnityLogo()
{
	
}

void UnityLogo::Start()
{
	SetPosition(GameEngineWindow::GetInst().GetScale().Half()+ (float4::DOWN * 10));
	UnityRenderer_ = CreateRenderer("UnityLogo.bmp");
	UnityRenderer_->SetAlpha(Alpha_);
}

void UnityLogo::Update()
{
	AlphaTime_ -= GameEngineTime::GetDeltaTime();

	if (0.0f >= AlphaTime_)
	{
		--Alpha_;
		AlphaTime_ = 0.008f;
	}

	UnityRenderer_->SetAlpha(Alpha_);

	if (Alpha_ <= 0)
	{
		GameEngine::GetInst().ChangeLevel("Play");
	}
}