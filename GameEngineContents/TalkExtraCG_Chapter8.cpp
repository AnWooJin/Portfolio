#include "TalkExtraCG_Chapter8.h"
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>

TalkExtraCG_Chapter8::TalkExtraCG_Chapter8()
	: MyRenderer_(nullptr),
	  MovePos_({0,0}),
	  Alpha_(100)

{
}

TalkExtraCG_Chapter8::~TalkExtraCG_Chapter8()
{
}

void TalkExtraCG_Chapter8::Start()
{
	if (MyRenderer_ == nullptr)
	{
		MyRenderer_ = CreateRenderer("extraDevilCG.bmp");
	}
}

void TalkExtraCG_Chapter8::Update()
{						
	MyRenderer_->SetAlpha(Alpha_);
	Alpha_ += static_cast<int>(800 * GameEngineTime::GetDeltaTime());
	if (false == GetPosition().CompareInt2D(MovePos_))
	{
		SetMove(float4::LEFT * 1000.0f * GameEngineTime::GetDeltaTime());
	}
	if (GetPosition().x <= MovePos_.x)
	{
		SetPosition(MovePos_);
	}
}