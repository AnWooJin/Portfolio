#include "BackGroundMap.h"
#include <GameEngineBase/GameEngineWindow.h>

BackGroundMap::BackGroundMap()
{
}

BackGroundMap::~BackGroundMap()
{
}

void BackGroundMap::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	MapRenderer_ = CreateRenderer();
}

void BackGroundMap::Render()
{

}

void BackGroundMap::MapSetting(int _Level)
{
	switch (_Level)
	{
	case 1:
	{
		MapRenderer_->SetImage("Chapter1_Map.bmp");
		break;
	}
	case 2:
	{
		MapRenderer_->SetImage("Chapter2_Map.bmp");
		break;
	}
	case 3:
	{
		MapRenderer_->SetImage("Chapter3_Map.bmp");
		break;
	}
	case 4:
	{
		MapRenderer_->SetImage("Chapter4_Map.bmp");
		break;
	}
	case 5:
	{
		MapRenderer_->SetImage("Chapter5_Map.bmp");
		break;
	}
	case 6:
	{
		MapRenderer_->SetImage("Chapter6_Map.bmp");
		break;
	}
	case 7:
	{
		MapRenderer_->SetImage("Chapter7_Map.bmp");
		break;
	}
	case 8:
	{
		MapRenderer_->SetImage("Chapter8_Map.bmp");
		break;
	}
	case 9:
	{
		MapRenderer_->SetImage("Chapter9_Map.bmp");
		break;
	}
	default:
		break;
	}
}