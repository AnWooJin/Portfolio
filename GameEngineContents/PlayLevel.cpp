#include "PlayLevel.h"
#include "Player.h"
#include "Skull.h"
#include "Block.h"
#include "DevilSD.h"
#include "SideUI.h"
#include "BackGroundMap.h"
#include "Thorn.h"
#include "HellTakerGame.h"


PlayLevel::PlayLevel()
	: MyPlayer_(nullptr)
	, MyMap_(nullptr)
	, MyDevil_(nullptr)
{
}

PlayLevel::~PlayLevel()
{
	
}

void PlayLevel::Loading()
{
	
	int Chapter = dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount();

	if (MyPlayer_ == nullptr)
	{
		MyDevil_ = CreateActor<DevilSD>(2);
		MyPlayer_ = CreateActor<Player>(2);
		MyMap_ = CreateActor<BackGroundMap>(0);
		CreateActor<SideUI>(1);
	}
	SkullSeting(Chapter);
	BlockSetting(Chapter);
	MyPlayer_->PlayerSetting(Chapter);
	MyDevil_->ImageSetting(Chapter);
	MyMap_->MapSetting(Chapter);
	SetCameraPos({ 0,0 });
}

void PlayLevel::Update()
{
	
}

void PlayLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	if (dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount() == 8)
	{
		SetCameraPos({0,612 });
	}
}



void PlayLevel::SkullSeting(int _ChapterLevel)
{
	switch (_ChapterLevel)
	{
	case 1:
	{
		Skulls_.reserve(3);
		for (size_t i = 0; i < 3; i++)
		{
			Skulls_.push_back(CreateActor<Skull>(2));
		}

		Skulls_[0]->SetPosition({ 642, 240 });
		Skulls_[1]->SetPosition({ 708, 305 });
		Skulls_[2]->SetPosition({ 576, 305 });
	}
	break;
	default:
		break;
	}
	
}


void PlayLevel::BlockSetting(int _ChaptherLevel)
{
	switch (_ChaptherLevel)
	{
	case 1:
		{
			Blocks_.reserve(4);
			for (size_t i = 0; i < 4; i++)
			{
				Blocks_.push_back(CreateActor<Block>(2));
			}

				Blocks_[0]->BlockRender_->SetIndex(0);
				Blocks_[0]->SetPosition({ 510, 435 + 10 });
				Blocks_[1]->BlockRender_->SetIndex(7);
				Blocks_[1]->SetPosition({ 708, 435 + 10 });
				Blocks_[2]->BlockRender_->SetIndex(2);
				Blocks_[2]->SetPosition({ 510,500 + 10 });
				Blocks_[3]->BlockRender_->SetIndex(3);
				Blocks_[3]->SetPosition({ 642,500 + 10 });
				break;
		}
	default:
		break;
	}
	
}