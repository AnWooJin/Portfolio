#include "BackGroundMap.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>

BackGroundMap::BackGroundMap()
	: MapRenderer_(nullptr)
{
}

BackGroundMap::~BackGroundMap()
{
}

void BackGroundMap::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());

	MapRenderer_ = CreateRenderer();
	MapRenderer_->CameraEffectOn();
}

void BackGroundMap::Render()
{

}


void BackGroundMap::ColMapSetting(int _Level)
{
	switch (_Level)
	{
	case 1:
	{
		MapRenderer_->SetImage("Chapter1_ColMap.bmp");
		break;
	}
	case 2:
	{
		MapRenderer_->SetImage("Chapter2_ColMap.bmp");
		break;
	}
	case 3:
	{
		MapRenderer_->SetImage("Chapter3_ColMap.bmp");
		break;
	}
	case 4:
	{
		MapRenderer_->SetImage("Chapter4_ColMap.bmp");
		break;
	}
	case 5:
	{
		MapRenderer_->SetImage("Chapter5_ColMap.bmp");
		break;
	}
	case 6:
	{
		MapRenderer_->SetImage("Chapter6_ColMap.bmp");
		break;
	}
	case 7:
	{
		MapRenderer_->SetImage("Chapter7_ColMap.bmp");
		break;
	}
	case 8:
	{
		SetPosition({ 640,666 });
		MapRenderer_->CameraEffectOn();
		MapRenderer_->SetImage("Chapter8_ColMap.bmp");
		break;
	}
	case 9:
	{
		SetPosition(GameEngineWindow::GetScale().Half());
		MapRenderer_->CameraEffectOff();
		MapRenderer_->SetImage("Chapter9_ColMap.bmp");
		break;
	}
	default:
		break;
	}
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
		SetPosition({ 640,666 });
		MapRenderer_->CameraEffectOn();
		MapRenderer_->SetImage("Chapter8_Map.bmp");
		break;
	}
	case 9:
	{
		SetPosition(GameEngineWindow::GetScale().Half());
		MapRenderer_->CameraEffectOff();
		MapRenderer_->SetImage("Chapter9_Map.bmp");
		break;
	}
	default:
		break;
	}
}
