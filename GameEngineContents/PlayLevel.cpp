#include "PlayLevel.h"
#include "Player.h"
#include "Skull.h"
#include "Block.h"
#include "DevilSD.h"
#include "SideUI.h"
#include "BackGroundMap.h"
#include "Thorn.h"
#include "HellTakerGame.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>


PlayLevel::PlayLevel()
	: Chapter_(1)
	, MyPlayer_(nullptr)
	, MyMap_(nullptr)
	, MyDevil_(nullptr)
	, IsBgmPlay_(false)
{
}

PlayLevel::~PlayLevel()
{
	
}

void PlayLevel::Loading()
{
	
	Chapter_ = dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount();
	if (MyPlayer_ == nullptr)
	{
		MyDevil_ = CreateActor<DevilSD>(static_cast<int>(PlayOrder::Devil));
		MyPlayer_ = CreateActor<Player>(static_cast<int>(PlayOrder::Player));
		MyMap_ = CreateActor<BackGroundMap>(static_cast<int>(PlayOrder::BackGround));
		CreateActor<SideUI>(static_cast<int>(PlayOrder::UI));
	}

	if (false == GameEngineInput::GetInst()->IsKey("DebugChange"))
	{
		GameEngineInput::GetInst()->CreateKey("DebugChange", 'i');
		GameEngineInput::GetInst()->CreateKey("Reset", 'r');
	}

	Skulls_.reserve(8);
	for (size_t i = 0; i < 8; i++)
	{
		Skulls_.push_back(CreateActor<Skull>(static_cast<int>(PlayOrder::SKull)));
	}
	Blocks_.reserve(13);
	for (size_t i = 0; i < 13; i++)
	{
		Blocks_.push_back(CreateActor<Block>(static_cast<int>(PlayOrder::Block)));
	}
	ActorOff();
	BlockSetting();
	SkullSetting();
	MyPlayer_->PlayerSetting(Chapter_);
	MyDevil_->ImageSetting(Chapter_);
	MyMap_->MapSetting(Chapter_);
}

void PlayLevel::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("DebugChange"))
	{
		IsDebugModeSwitch();
	}
	if (true == GameEngineInput::GetInst()->IsDown("Reset"))
	{
		GameEngine::GetInst().ChangeLevel("SceneChange");
	}
}

void PlayLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	if (false == IsBgmPlay_)
	{
		PlayBgmPlayer_ = GameEngineSound::SoundPlayControl("PlayBGM.wav");
		IsBgmPlay_ = true;
	}
	
	Chapter_ = dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount();
	SetCameraPos({ 0,0 });
	if (8 == Chapter_)
	{
		SetCameraPos({0,612 });
	}

	if (nullptr == MyDevil_)
	{
		MyDevil_ = CreateActor<DevilSD>(static_cast<int>(PlayOrder::Devil));
		MyDevil_->ImageSetting(Chapter_);

	}
	
	if (false == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetIsSuccess())
	{
		MyPlayer_->PlayerSetting(Chapter_);
		BlockSetting();
		SkullSetting();
	}
}

void PlayLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	if (true == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetIsSuccess())
	{
		ActorOff();
	}
	if (nullptr != MyDevil_)
	{
		MyDevil_->Death();
		MyDevil_ = nullptr;
	}

}


void PlayLevel::ActorOff()
{
	for (size_t i = 0; i < Skulls_.size(); i++)
	{
		Skulls_[i]->Off();
	}
	for (size_t i = 0; i < Blocks_.size(); i++)
	{
		Blocks_[i]->Off();
	}

}


void PlayLevel::SkullSetting()
{
	switch (Chapter_)
	{
	case 1:
	{
		SKull_Chapter1Set();
		break;
	}
	case 2:
	{
		SKull_Chapter2Set();
		break;
	}
	case 3:
	{
		SKull_Chapter3Set();
		break;
	}
	case 4:
	{
		SKull_Chapter4Set();
		break;
	}
	case 5:
	{
		SKull_Chapter5Set();
		break;
	}
	case 6:
	{
		SKull_Chapter6Set();
		break;
	}
	case 7:
	{
		SKull_Chapter7Set();
		break;
	}
	case 8:
	{
		SKull_Chapter8Set();
		break;
	}
	default:
		break;
	}
	
}


void PlayLevel::BlockSetting()
{
	switch (Chapter_)
	{
	case 1:
	{
		Block_Chapter1Set();
		break;
	}
	case 2:
	{
		Block_Chapter2Set();
		break;
	}
	case 3:
	{
		Block_Chapter3Set();
		break;
	}
	case 4:
	{
		Block_Chapter4Set();
		break;
	}
	case 5:
	{
		Block_Chapter5Set();
		break;
	}
	case 6:
	{
		Block_Chapter6Set();
		break;
	}
	case 7:
	{
		Block_Chapter7Set();
		break;
	}
	case 8:
	{
		Block_Chapter8Set();
		break;
	}
	default:
		break;
	}
	
}


void PlayLevel::ThornSetting()
{

}




//////////////////////////////////////////////  블록의 위치와 이미지를 정해주는 함수

void PlayLevel::Block_Chapter1Set()
{
	Blocks_[0]->On();
	Blocks_[0]->BlockRender_->SetIndex(0);
	Blocks_[0]->SetPosition({ 510, 435 + 10 });
	Blocks_[1]->On();
	Blocks_[1]->BlockRender_->SetIndex(7);
	Blocks_[1]->SetPosition({ 708, 435 + 10 });
	Blocks_[2]->On();
	Blocks_[2]->BlockRender_->SetIndex(2);
	Blocks_[2]->SetPosition({ 510,500 + 10 });
	Blocks_[3]->On();
	Blocks_[3]->BlockRender_->SetIndex(3);
	Blocks_[3]->SetPosition({ 642,500 + 10 });
}

void PlayLevel::Block_Chapter2Set()
{
	Blocks_[0]->On();
	Blocks_[0]->BlockRender_->SetIndex(1);
	Blocks_[0]->SetPosition({ 710, 315 + 10 });
	Blocks_[1]->On();
	Blocks_[1]->BlockRender_->SetIndex(3);
	Blocks_[1]->SetPosition({ 775, 315 + 10 });
	Blocks_[2]->On();
	Blocks_[2]->BlockRender_->SetIndex(5);
	Blocks_[2]->SetPosition({ 840, 315 + 10 });
}

void PlayLevel::Block_Chapter3Set()
{
}

void PlayLevel::Block_Chapter4Set()
{
	Blocks_[0]->On();
	Blocks_[0]->BlockRender_->SetIndex(6);
	Blocks_[0]->SetPosition({ 670, 212 + 10 });
	Blocks_[1]->On();
	Blocks_[1]->BlockRender_->SetIndex(1);
	Blocks_[1]->SetPosition({ 605, 278 + 10 });
	Blocks_[2]->On();
	Blocks_[2]->BlockRender_->SetIndex(5);
	Blocks_[2]->SetPosition({ 475, 278 + 10 });
	Blocks_[3]->On();
	Blocks_[3]->BlockRender_->SetIndex(7);
	Blocks_[3]->SetPosition({ 410, 344 + 10 });
	Blocks_[4]->On();
	Blocks_[4]->BlockRender_->SetIndex(4);
	Blocks_[4]->SetPosition({ 540, 344 + 10 });
	Blocks_[5]->On();
	Blocks_[5]->BlockRender_->SetIndex(0);
	Blocks_[5]->SetPosition({ 670, 344 + 10 });
	Blocks_[6]->On();
	Blocks_[6]->BlockRender_->SetIndex(5);
	Blocks_[6]->SetPosition({ 735, 344 + 10 });
	Blocks_[7]->On();
	Blocks_[7]->BlockRender_->SetIndex(6);
	Blocks_[7]->SetPosition({ 475, 410 + 10 });
	Blocks_[8]->On();
	Blocks_[8]->BlockRender_->SetIndex(2);
	Blocks_[8]->SetPosition({ 605, 410 + 10 });
	Blocks_[9]->On();
	Blocks_[9]->BlockRender_->SetIndex(1);
	Blocks_[9]->SetPosition({ 735, 410 + 10 });
	Blocks_[10]->On();
	Blocks_[10]->BlockRender_->SetIndex(9);
	Blocks_[10]->SetPosition({ 800, 410 + 10 });
	Blocks_[11]->On();
	Blocks_[11]->BlockRender_->SetIndex(3);
	Blocks_[11]->SetPosition({ 540, 476 + 10 });
	Blocks_[12]->On();
	Blocks_[12]->BlockRender_->SetIndex(7);
	Blocks_[12]->SetPosition({ 670, 476 + 10 });
}

void PlayLevel::Block_Chapter5Set()
{
	Blocks_[0]->On();
	Blocks_[0]->BlockRender_->SetIndex(9);
	Blocks_[0]->SetPosition({ 740, 208 + 10 });
	Blocks_[1]->On();
	Blocks_[1]->BlockRender_->SetIndex(1);
	Blocks_[1]->SetPosition({ 740, 274 + 10 });
	Blocks_[2]->On();
	Blocks_[2]->BlockRender_->SetIndex(5);
	Blocks_[2]->SetPosition({ 610, 406 + 10 });
	Blocks_[3]->On();
	Blocks_[3]->BlockRender_->SetIndex(3);
	Blocks_[3]->SetPosition({ 675, 406 + 10 });
	Blocks_[4]->On();
	Blocks_[4]->BlockRender_->SetIndex(7);
	Blocks_[4]->SetPosition({ 740, 406 + 10 });
	Blocks_[5]->On();
	Blocks_[5]->BlockRender_->SetIndex(0);
	Blocks_[5]->SetPosition({ 805, 406 + 10 });
}

void PlayLevel::Block_Chapter6Set()
{
	Blocks_[0]->On();
	Blocks_[0]->BlockRender_->SetIndex(4);
	Blocks_[0]->SetPosition({ 510, 180 + 10 });
	Blocks_[1]->On();
	Blocks_[1]->BlockRender_->SetIndex(3);
	Blocks_[1]->SetPosition({ 575, 180 + 10 });
	Blocks_[2]->On();
	Blocks_[2]->BlockRender_->SetIndex(2);
	Blocks_[2]->SetPosition({ 640, 180 + 10 });
	Blocks_[3]->On();
	Blocks_[3]->BlockRender_->SetIndex(1);
	Blocks_[3]->SetPosition({ 575, 312 + 10 });
	Blocks_[4]->On();
	Blocks_[4]->BlockRender_->SetIndex(0);
	Blocks_[4]->SetPosition({ 640, 378 + 10 });
	Blocks_[5]->On();
	Blocks_[5]->BlockRender_->SetIndex(7);
	Blocks_[5]->SetPosition({ 705, 378 + 10 });
	Blocks_[6]->On();
	Blocks_[6]->BlockRender_->SetIndex(6);
	Blocks_[6]->SetPosition({ 640, 444 + 10 });
	Blocks_[7]->On();
	Blocks_[7]->BlockRender_->SetIndex(8);
	Blocks_[7]->SetPosition({ 770, 510 + 10 });
}

void PlayLevel::Block_Chapter7Set()
{
	Blocks_[0]->On();
	Blocks_[0]->BlockRender_->SetIndex(7);
	Blocks_[0]->SetPosition({ 675, 272 + 10 });
	Blocks_[1]->On();
	Blocks_[1]->BlockRender_->SetIndex(3);
	Blocks_[1]->SetPosition({ 740, 272 + 10 });
	Blocks_[2]->On();
	Blocks_[2]->BlockRender_->SetIndex(5);
	Blocks_[2]->SetPosition({ 805, 272 + 10 });
	Blocks_[3]->On();
	Blocks_[3]->BlockRender_->SetIndex(4);
	Blocks_[3]->SetPosition({ 540, 338 + 10 });
	Blocks_[4]->On();
	Blocks_[4]->BlockRender_->SetIndex(0);
	Blocks_[4]->SetPosition({ 740, 338 + 10 });
}

void PlayLevel::Block_Chapter8Set()
{

}


/////////////////////////////////////////////  스컬들의 위치와 업데이트를 끈 스컬을 다시 켜주는 함수들

void PlayLevel::SKull_Chapter1Set()
{
	Skulls_[0]->SetPosition({ 642, 240 });
	Skulls_[1]->SetPosition({ 708, 305 });
	Skulls_[2]->SetPosition({ 576, 305 });
	Skulls_[0]->On();
	Skulls_[1]->On();
	Skulls_[2]->On();
}

void PlayLevel::SKull_Chapter2Set()
{
	Skulls_[0]->SetPosition({ 510, 249 });
	Skulls_[1]->SetPosition({ 775, 437 });
	Skulls_[2]->SetPosition({ 840, 503 });
	Skulls_[0]->On();
	Skulls_[1]->On();
	Skulls_[2]->On();
}

void PlayLevel::SKull_Chapter3Set()
{
	Skulls_[0]->SetPosition({ 670, 406 });
	Skulls_[1]->SetPosition({ 735, 538 });
	Skulls_[0]->On();
	Skulls_[1]->On();
}

void PlayLevel::SKull_Chapter4Set()
{
	
}

void PlayLevel::SKull_Chapter5Set()
{
	Skulls_[0]->SetPosition({ 475, 406 });
	Skulls_[0]->On();
}

void PlayLevel::SKull_Chapter6Set()
{
	Skulls_[0]->SetPosition({ 510, 378 });
	Skulls_[0]->On();
	Skulls_[1]->SetPosition({ 770, 444 });
	Skulls_[1]->On();
}

void PlayLevel::SKull_Chapter7Set()
{
	Skulls_[0]->SetPosition({ 670, 340 });
	Skulls_[0]->On();
	Skulls_[1]->SetPosition({ 475, 340 });
	Skulls_[1]->On();
	Skulls_[2]->SetPosition({ 605, 406 });
	Skulls_[2]->On();
}

void PlayLevel::SKull_Chapter8Set()
{
	Skulls_[0]->SetPosition({ 640, 1010 });
	Skulls_[0]->On();
	Skulls_[1]->SetPosition({ 640, 944 });
	Skulls_[1]->On();
	Skulls_[2]->SetPosition({ 640, 878 });
	Skulls_[2]->On();
	Skulls_[3]->SetPosition({ 640, 812 });
	Skulls_[3]->On();
	Skulls_[4]->SetPosition({ 640, 746 });
	Skulls_[4]->On();
	Skulls_[5]->SetPosition({ 640, 680 });
	Skulls_[5]->On();
	Skulls_[6]->SetPosition({ 640, 614 });
	Skulls_[6]->On();
	Skulls_[7]->SetPosition({ 640, 548 });
	Skulls_[7]->On();
	
}