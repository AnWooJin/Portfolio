#include "GameEngineImage.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
#pragma comment(lib, "msimg32.lib")
GameEngineImage::GameEngineImage()
	:ImageDC_(nullptr)
{
}

GameEngineImage::~GameEngineImage()
{
}

bool GameEngineImage::Create(HDC _DC)
{
	ImageDC_ = _DC;
	ImageScaleCheck();
	return true;
}


bool GameEngineImage::Create(float4 _Scale)
{
	if (true == _Scale.IsZero2D())
	{
		MsgBoxAssert("크기가 0인 이미지를 제작하려고 했습니다.");
		return false;
	}

	// 먼저 이미지 크기만한 비트맵을 만든다.
	BitMap_ = CreateCompatibleBitmap(GameEngineWindow::GetHDC(), _Scale.ix(), _Scale.iy());

	// 만든 비트맵과 연결시킬 ImageDC를 만든다(window에서 임의로 1 X 1 크기의 비트맵과 연결시켜준다)
	ImageDC_ = CreateCompatibleDC(nullptr);

	if (nullptr == ImageDC_)
	{
		MsgBoxAssert("ImageDC 생성에 실패했습니다.");
	}
	// 만든 비트맵과 ImageDC를 연결시킨다.
	OldBitMap_ = (HBITMAP)SelectObject(ImageDC_, BitMap_);

	ImageScaleCheck();

	return true;
}

void GameEngineImage::ImageScaleCheck()
{
	// DC 내부에 들어있는 비트맵을 꺼내오는 함수
	HBITMAP CurrentBitMap = (HBITMAP)GetCurrentObject(ImageDC_, OBJ_BITMAP);
	GetObject(CurrentBitMap, sizeof(BITMAP), &Info_);
}

void GameEngineImage::BitCopy(GameEngineImage* _Other)
{
	BitCopy(_Other, { 0,0 }, { 0, 0 }, _Other->GetScale());
}

void GameEngineImage::BitCopy(GameEngineImage* _Other, const float4& _CopyPos, const float4& _OtherPivot, const float4& _OtherPivotScale)
{
	// 윈도우에서 지원하는 일반적인 DC VS DC의 복사함수
	BitBlt(
		ImageDC_,  // 이 DC에 복사해라
		_CopyPos.ix(), // 내 이미지의 X
		_CopyPos.iy(), // 내 이미지의 Y 부분에 복사해라
		_OtherPivotScale.ix(), //  내 이미지의 이 크기만큼 X
		_OtherPivotScale.iy(),	// 내 이미지의 이 크기만큼 Y
		_Other->ImageDC_, // 복사하려는 대상의 DC
		_OtherPivot.ix(), // 복사하려는 대상의 시작점X
		_OtherPivot.iy(), // 복사하려는 대상의 시작점Y
		SRCCOPY  // 복사하라는 명령
	);
}