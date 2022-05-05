#include "Block.h"
#include "HellTakerGame.h"
#include "MoveEffect.h"
#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineSound.h>



Block::Block()
	: MyCollision_(nullptr)
	, MyPlayer_(nullptr)
	, ColMapImage_(nullptr)
	, BlockRender_ (nullptr)
{
}

Block::~Block()
{
}

void Block::Start()
{
	BlockRender_ = CreateRenderer("Blocks_56.bmp");
	MyCollision_ = CreateCollision("Block", { 40,40 });
	MyPlayer_ = GetLevel()->FindActor<Player>("Player");
}

void Block::Update()
{
	if (MyCollision_->CollisionCheck("Player"))
	{	
		BlockPush();
	}
}

void Block::CreateMoveEffect()
{

	GameEngineActor* Actor = GetLevel()->CreateActor<MoveEffect>(1, "Move");
	Actor->SetPosition(GetPosition() + (float4::DOWN * 20.0f));
	if (8 == dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount())
	{
		Actor->SetPosition(GetLevel()->GetCameraPos() + GetPosition() + (float4::DOWN * 20.0f));
	}
}


void Block::BlockPush()
{
	float4 PlayerPos = MyPlayer_->GetPosition();
	float4 MovePos = float4::ZERO;

	if (GetPosition().x > PlayerPos.x)
	{
		MovePos = float4::RIGHT * 66;
	}
	else if (GetPosition().x < PlayerPos.x)
	{
		MovePos = float4::LEFT * 66;
	}
	else if (GetPosition().y > PlayerPos.y)
	{
		MovePos = float4::DOWN * 65;
	}
	else if (GetPosition().y < PlayerPos.y)
	{
		MovePos = float4::UP * 65;
	}


	BlockMoveCheck(MovePos);

}

void Block::BlockMoveCheck(float4 _MovePos)
{
	int Color = ColMapImage_->GetImagePixel(GetPosition() + _MovePos + GetLevel()->GetCameraPos());
	if (Color == RGB(0, 0, 0))
	{
		return;
	}

	SetMove(_MovePos);

	_MovePos *= -1.0f;
	
	if (MyCollision_->CollisionCheck("Block"))
	{
		SetMove(_MovePos);
		return;
	}

	if (MyCollision_->CollisionCheck("Skull"))
	{
		SetMove(_MovePos);
		return;
	}

	GameEngineSound::SoundPlayOneShot("Block_Move.wav");
	CreateMoveEffect();
}


void Block::SetColImage(int _Chapter)
{
	switch (_Chapter)
	{
	case 1:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter1_ColMap.bmp");
		break;
	case 2:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter2_ColMap.bmp");
		break;
	case 3:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter3_ColMap.bmp");
		break;
	case 4:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter4_ColMap.bmp");
		break;
	case 5:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter5_ColMap.bmp");
		break;
	case 6:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter6_ColMap.bmp");
		break;
	case 7:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter7_ColMap.bmp");
		break;
	case 8:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter8_ColMap.bmp");
		break;
	case 9:
		ColMapImage_ = GameEngineImageManager::GetInst()->Find("Chapter9_ColMap.bmp");
		break;
	default:
		break;
	}
}

void Block::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	int Chapter = dynamic_cast<HellTakerGame&>(HellTakerGame::GetInst()).GetChapterCount();
	SetColImage(Chapter);	
}