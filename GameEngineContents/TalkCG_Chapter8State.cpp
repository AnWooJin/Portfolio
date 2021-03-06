#include "Talk_Chapter8Level.h"
#include "TalkSelectActor_Chapter8.h"
#include "TalkCG_Chapter8.h"
#include "HellTakerGame.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineWindow.h>

void TalkCG_Chapter8::AnimationStart()
{
	 	MyRenderer_->ChangeAnimation("TalkCG_Chapter8");
}

void TalkCG_Chapter8::IdleStart()
{
	if (MyRenderer_ != nullptr)
	{
		MyRenderer_->SetImageAnimationReset("Chapter8CG_Idle.bmp");

	}
	else
	{
		MyRenderer_ = CreateRenderer("Chapter8CG_Idle.bmp");
	}
}

void TalkCG_Chapter8::Success0Start()
{
	if (MyRenderer_ != nullptr)
	{
		MyRenderer_->SetImageAnimationReset("Chapter8CG_Success00.bmp");
		
	}
	else
	{
		MyRenderer_ = CreateRenderer("Chapter8CG_Success00.bmp");
	}
}

void TalkCG_Chapter8::Success1Start()
{
	if (MyRenderer_ != nullptr)
	{
		MyRenderer_->SetImageAnimationReset("Chapter8CG_Success01.bmp");
	}
	else
	{
		MyRenderer_ = CreateRenderer("Chapter8CG_Success01.bmp");
	}
}

void TalkCG_Chapter8::AnimationUpdate()
{
	if (false == VineSoundPlay_ && 5 == MyRenderer_->CurrentAnimation()->WorldCurrentFrame())
	{
		GameEngineSound::SoundPlayOneShot("lucifer_intro_vine_.wav");
		VineSoundPlay_ = true;
	}
	if (false == SkeletonSoundPlay_ && 82 == MyRenderer_->CurrentAnimation()->WorldCurrentFrame())
	{
		GameEngineSound::SoundPlayOneShot("lucifer_intro_skeleton_01.wav");
		SkeletonSoundPlay_ = true;
	}
	if (true == MyRenderer_->IsEndAnimation())
	{
		GameEngineSound::SoundPlayOneShot("lucifer_intro_dialogue_start_.wav");
		ChangeState(TalkCGState_Chapter8::Idle);
	}
}

void TalkCG_Chapter8::IdleUpdate()
{
	TalkSelectActor_Chapter8* SelectActor = GetLevel()->FindActor<TalkSelectActor_Chapter8>("TalkSelectActor_Chapter8");
	if (true == SelectActor->GetIsSelect0() && 
		true == dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).GetIsSuccess())
	{
		ChangeState(TalkCGState_Chapter8::Success0);
	}
}

void TalkCG_Chapter8::Success0Update()
{
	TalkSelectActor_Chapter8* SelectActor = GetLevel()->FindActor<TalkSelectActor_Chapter8>("TalkSelectActor_Chapter8");

	if (true == SelectActor->GetIsSelect1() &&
		true == dynamic_cast<HellTakerGame&>(GameEngine::GetInst()).GetIsSuccess())
	{
		ChangeState(TalkCGState_Chapter8::Success1);
	}
}

void TalkCG_Chapter8::Success1Update()
{

}


