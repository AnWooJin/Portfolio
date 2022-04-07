#include "Chapter1Level.h"
#include "Chapter1DevilSD.h"
#include "Player.h"
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