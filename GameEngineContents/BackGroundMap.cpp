#include "BackGroundMap.h"
#include <GameEngineBase/GameEngineWindow.h>

BackGroundMap::BackGroundMap()
	: ChapterLevel_(1)
{
}

BackGroundMap::~BackGroundMap()
{
}

void BackGroundMap::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	MapSetting(ChapterLevel_);
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
		CreateRenderer("chapter1_Map.bmp");
		CreateRenderer("SideUI.bmp");
	}
		break;
	default:
		break;
	}
}