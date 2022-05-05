#include "PlayLevel.h"
#include "Player.h"
#include "Skull.h"
#include "Block.h"
#include "Thorn.h"
#include "LockBlock.h"
#include "Key.h"
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
	, LockBlock_(nullptr)
	, MyKey_(nullptr)
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
	LockBlock_ = CreateActor<LockBlock>(static_cast<int>(PlayOrder::Block));
	MyKey_ = CreateActor<Key>(1);
	ActorOff();
	BlockSetting();
	SkullSetting();
	ThornSetting();

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
	ThornSetting();
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
	LockBlock_->Off();
	MyKey_->Off();
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
	switch (Chapter_)
	{
	case 1:
	{
		Thorn_Chapter1Set();
		break;
	}
	case 2:
	{
		Thorn_Chapter2Set();
		break;
	}
	case 3:
	{
		Thorn_Chapter3Set();
		break;
	}
	case 4:
	{
		Thorn_Chapter4Set();
		break;
	}
	case 5:
	{
		Thorn_Chapter5Set();
		break;
	}
	case 6:
	{
		Thorn_Chapter6Set();
		break;
	}
	case 7:
	{
		Thorn_Chapter7Set();
		break;
	}
	case 8:
	{
		Thorn_Chapter8Set();
		break;
	}
	default:
		break;
	}

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
	Blocks_[0]->SetPosition({ 440 + 66 * 4, 315 + 10 });
	Blocks_[1]->On();
	Blocks_[1]->BlockRender_->SetIndex(3);
	Blocks_[1]->SetPosition({ 440 + 66 * 5, 315 + 10 });
	Blocks_[2]->On();
	Blocks_[2]->BlockRender_->SetIndex(5);
	Blocks_[2]->SetPosition({ 440 + 66 * 6, 315 + 10 });
}

void PlayLevel::Block_Chapter3Set()
{
	LockBlock_->On();
	LockBlock_->SetPosition({ 870 - 66 , 208 });
	MyKey_->On();
	MyKey_->SetPosition({870 - 66 * 7, 468});
}

void PlayLevel::Block_Chapter4Set()
{
	LockBlock_->On();
	LockBlock_->SetPosition({ 405 + 66 * 5 ,278 });
	MyKey_->On();
	MyKey_->SetPosition({ 405 + 66 * 2 ,212 });
	Blocks_[0]->On();
	Blocks_[0]->BlockRender_->SetIndex(6);
	Blocks_[0]->SetPosition({ 405 + 66 * 4, 212 + 10 });
	Blocks_[1]->On();
	Blocks_[1]->BlockRender_->SetIndex(1);
	Blocks_[1]->SetPosition({ 405 + 66, 278 + 10 });
	Blocks_[2]->On();
	Blocks_[2]->BlockRender_->SetIndex(5);
	Blocks_[2]->SetPosition({ 405 + 66 * 3, 278 + 10 });
	Blocks_[3]->On();
	Blocks_[3]->BlockRender_->SetIndex(7);
	Blocks_[3]->SetPosition({ 405, 344 + 10 });
	Blocks_[4]->On();
	Blocks_[4]->BlockRender_->SetIndex(4);
	Blocks_[4]->SetPosition({ 405 + 66 * 2, 344 + 10 });
	Blocks_[5]->On();
	Blocks_[5]->BlockRender_->SetIndex(0);
	Blocks_[5]->SetPosition({ 405 + 66 * 4, 344 + 10 });
	Blocks_[6]->On();
	Blocks_[6]->BlockRender_->SetIndex(5);
	Blocks_[6]->SetPosition({ 405 + 66 * 5, 344 + 10 });
	Blocks_[7]->On();
	Blocks_[7]->BlockRender_->SetIndex(6);
	Blocks_[7]->SetPosition({ 405 + 66, 410 + 10 });
	Blocks_[8]->On();
	Blocks_[8]->BlockRender_->SetIndex(2);
	Blocks_[8]->SetPosition({ 405 + 66 * 3, 410 + 10 });
	Blocks_[9]->On();
	Blocks_[9]->BlockRender_->SetIndex(1);
	Blocks_[9]->SetPosition({ 405 + 66 * 5, 410 + 10 });
	Blocks_[10]->On();
	Blocks_[10]->BlockRender_->SetIndex(9);
	Blocks_[10]->SetPosition({ 405 + 66 * 6, 410 + 10 });
	Blocks_[11]->On();
	Blocks_[11]->BlockRender_->SetIndex(3);
	Blocks_[11]->SetPosition({ 405 + 66 * 2, 476 + 10 });
	Blocks_[12]->On();
	Blocks_[12]->BlockRender_->SetIndex(7);
	Blocks_[12]->SetPosition({ 405 + 66 * 4, 476 + 10 });
}

void PlayLevel::Block_Chapter5Set()
{
	LockBlock_->On();
	LockBlock_->SetPosition({ 475 + 66 * 3 , 208 });
	Blocks_[0]->On();
	Blocks_[0]->BlockRender_->SetIndex(10);
	Blocks_[0]->SetPosition({ 475 + 66 *4, 208 + 10 });
	Blocks_[1]->On();
	Blocks_[1]->BlockRender_->SetIndex(1);
	Blocks_[1]->SetPosition({ 475 + 66 * 4, 274 + 10 });
	Blocks_[2]->On();
	Blocks_[2]->BlockRender_->SetIndex(5);
	Blocks_[2]->SetPosition({ 475 + 66 * 2, 406 + 10 });
	Blocks_[3]->On();
	Blocks_[3]->BlockRender_->SetIndex(3);
	Blocks_[3]->SetPosition({ 475 + 66 * 3, 406 + 10 });
	Blocks_[4]->On();
	Blocks_[4]->BlockRender_->SetIndex(7);
	Blocks_[4]->SetPosition({ 475 + 66 * 4, 406 + 10 });
	Blocks_[5]->On();
	Blocks_[5]->BlockRender_->SetIndex(0);
	Blocks_[5]->SetPosition({ 475 + 66 * 5, 406 + 10 });
}

void PlayLevel::Block_Chapter6Set()
{
	LockBlock_->On();
	LockBlock_->SetPosition({ 575 + 66 * 2, 510 + 10 });
	Blocks_[0]->On();
	Blocks_[0]->BlockRender_->SetIndex(4);
	Blocks_[0]->SetPosition({ 575 - 66, 180 + 10 });
	Blocks_[1]->On();
	Blocks_[1]->BlockRender_->SetIndex(3);
	Blocks_[1]->SetPosition({ 575, 180 + 10 });
	Blocks_[2]->On();
	Blocks_[2]->BlockRender_->SetIndex(2);
	Blocks_[2]->SetPosition({ 575 + 66, 180 + 10 });
	Blocks_[3]->On();
	Blocks_[3]->BlockRender_->SetIndex(1);
	Blocks_[3]->SetPosition({ 575, 312 + 10 });
	Blocks_[4]->On();
	Blocks_[4]->BlockRender_->SetIndex(0);
	Blocks_[4]->SetPosition({ 575 + 66, 378 + 10 });
	Blocks_[5]->On();
	Blocks_[5]->BlockRender_->SetIndex(7);
	Blocks_[5]->SetPosition({ 575 + 66 * 2, 378 + 10 });
	Blocks_[6]->On();
	Blocks_[6]->BlockRender_->SetIndex(6);
	Blocks_[6]->SetPosition({ 575 + 66, 444 + 10 });
	Blocks_[7]->On();
	Blocks_[7]->BlockRender_->SetIndex(8);
	Blocks_[7]->SetPosition({ 575 + 66 * 3, 510 + 10 });
}

void PlayLevel::Block_Chapter7Set()
{
	LockBlock_->On();
	LockBlock_->SetPosition({ 805 - 66, 208 + 10 });
	Blocks_[0]->On();
	Blocks_[0]->BlockRender_->SetIndex(7);
	Blocks_[0]->SetPosition({ 805 - 66 * 2, 272 + 10 });
	Blocks_[1]->On();
	Blocks_[1]->BlockRender_->SetIndex(3);
	Blocks_[1]->SetPosition({ 805 - 66, 272 + 10 });
	Blocks_[2]->On();
	Blocks_[2]->BlockRender_->SetIndex(5);
	Blocks_[2]->SetPosition({ 805, 272 + 10 });
	Blocks_[3]->On();
	Blocks_[3]->BlockRender_->SetIndex(4);
	Blocks_[3]->SetPosition({ 805 - 66 * 4, 338 + 10 });
	Blocks_[4]->On();
	Blocks_[4]->BlockRender_->SetIndex(0);
	Blocks_[4]->SetPosition({ 805 - 66, 338 + 10 });
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
	Skulls_[0]->SetPosition({ 440 + 66, 249 });
	Skulls_[1]->SetPosition({ 440 + 66 * 5, 437 });
	Skulls_[2]->SetPosition({ 440 + 66 * 6, 503 });
	Skulls_[0]->On();
	Skulls_[1]->On();
	Skulls_[2]->On();
}

void PlayLevel::SKull_Chapter3Set()
{
	Skulls_[0]->SetPosition({ 870 - 66 * 3, 406 });
	Skulls_[1]->SetPosition({ 870 - 66 * 2, 538 });
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
	Skulls_[0]->SetPosition({ 575 - 66, 378 });
	Skulls_[0]->On();
	Skulls_[1]->SetPosition({ 575 + 66 * 3, 444 });
	Skulls_[1]->On();
}

void PlayLevel::SKull_Chapter7Set()
{
	Skulls_[0]->SetPosition({ 805 - 66 * 2, 340 });
	Skulls_[0]->On();
	Skulls_[1]->SetPosition({ 805 - 66 * 5, 340 });
	Skulls_[1]->On();
	Skulls_[2]->SetPosition({ 805 - 66 * 3, 406 });
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


//////////////////////////////////  가시의 위치와 상태를 지정해주는 함수들

void PlayLevel::Thorn_Chapter1Set()
{

}

void PlayLevel::Thorn_Chapter2Set()
{

}


void PlayLevel::Thorn_Chapter3Set()
{
	CreateActor<Thorn>(static_cast<int>(PlayOrder::Thorn))->SetPosition({ 870 - 66 * 4, 274 + 15 });
	CreateActor<Thorn>(static_cast<int>(PlayOrder::Thorn))->SetPosition({ 870 - 66 * 3, 274 + 15 });
	CreateActor<Thorn>(static_cast<int>(PlayOrder::Thorn))->SetPosition({ 870 - 66 * 5, 340 + 15 });
	CreateActor<Thorn>(static_cast<int>(PlayOrder::Thorn))->SetPosition({ 870 - 66 * 3, 340 + 15 });
	CreateActor<Thorn>(static_cast<int>(PlayOrder::Thorn))->SetPosition({ 870 - 66 * 2, 406 +15 });
	CreateActor<Thorn>(static_cast<int>(PlayOrder::Thorn))->SetPosition({ 870 - 66, 406 + 15});
	CreateActor<Thorn>(static_cast<int>(PlayOrder::Thorn))->SetPosition({ 870 - 66 * 5, 472 + 15 });
	CreateActor<Thorn>(static_cast<int>(PlayOrder::Thorn))->SetPosition({ 870 - 66 * 3, 472 + 15 });
}


void PlayLevel::Thorn_Chapter4Set()
{
	CreateActor<Thorn>(static_cast<int>(PlayOrder::Thorn))->SetPosition({ 405 + 66 * 2, 278 + 15 });
	CreateActor<Thorn>(static_cast<int>(PlayOrder::Thorn))->SetPosition({ 405 + 66 * 3, 278 + 15 });
}

void PlayLevel::Thorn_Chapter5Set()
{

}


void PlayLevel::Thorn_Chapter6Set()
{

}


void PlayLevel::Thorn_Chapter7Set()
{

}


void PlayLevel::Thorn_Chapter8Set()
{

}


