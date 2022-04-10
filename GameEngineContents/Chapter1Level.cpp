#include "Chapter1Level.h"
#include "Chapter1DevilSD.h"
#include "Player.h"
#include "Skull.h"
#include "Block.h"
#include "Thorn.h"
#include "Chapter1Map.h"

Chapter1Level::Chapter1Level()
	: MyPlayer_(nullptr)
{
}

Chapter1Level::~Chapter1Level()
{

}

void Chapter1Level::Loading()
{
	Skulls_.reserve(3);
	Blocks_.reserve(4);
	
	SkullSeting();
	BlockSetting();
	CreateActor<Thorn>(1);
}

void Chapter1Level::Update()
{

}

void  Chapter1Level::LevelChangeStart()
{
	if (MyPlayer_ == nullptr)
	{
		CreateActor<Chapter1DevilSD>(1);
		MyPlayer_ = CreateActor<Player>(1);
		CreateActor<Chapter1Map>(0);
	}
}


void Chapter1Level::SkullSeting()
{
	for (size_t i = 0; i < 3; i++)
	{
		Skulls_.push_back(CreateActor<Skull>(2));
	}

	Skulls_[0]->SetPosition({ 642, 240 });
	Skulls_[1]->SetPosition({ 708, 305 });
	Skulls_[2]->SetPosition({ 576, 305 });
}


void Chapter1Level::BlockSetting()
{
	for (size_t i = 0; i < 4; i++)
	{
		Blocks_.push_back(CreateActor<Block>(2));
	}

	Blocks_[0]->BlockRender_->SetIndex(0);
	Blocks_[0]->SetPosition({ 510, 435+10});
	Blocks_[1]->BlockRender_->SetIndex(7);
	Blocks_[1]->SetPosition({ 708, 435+10});
	Blocks_[2]->BlockRender_->SetIndex(2);
	Blocks_[2]->SetPosition({ 510,500+10});
	Blocks_[3]->BlockRender_->SetIndex(3);
	Blocks_[3]->SetPosition({ 642,500+10});
}