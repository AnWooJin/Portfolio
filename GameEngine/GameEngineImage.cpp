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
		MsgBoxAssert("ũ�Ⱑ 0�� �̹����� �����Ϸ��� �߽��ϴ�.");
		return false;
	}

	// ���� �̹��� ũ�⸸�� ��Ʈ���� �����.
	BitMap_ = CreateCompatibleBitmap(GameEngineWindow::GetHDC(), _Scale.ix(), _Scale.iy());

	// ���� ��Ʈ�ʰ� �����ų ImageDC�� �����(window���� ���Ƿ� 1 X 1 ũ���� ��Ʈ�ʰ� ��������ش�)
	ImageDC_ = CreateCompatibleDC(nullptr);

	if (nullptr == ImageDC_)
	{
		MsgBoxAssert("ImageDC ������ �����߽��ϴ�.");
	}
	// ���� ��Ʈ�ʰ� ImageDC�� �����Ų��.
	OldBitMap_ = (HBITMAP)SelectObject(ImageDC_, BitMap_);

	ImageScaleCheck();

	return true;
}

void GameEngineImage::ImageScaleCheck()
{
	// DC ���ο� ����ִ� ��Ʈ���� �������� �Լ�
	HBITMAP CurrentBitMap = (HBITMAP)GetCurrentObject(ImageDC_, OBJ_BITMAP);
	GetObject(CurrentBitMap, sizeof(BITMAP), &Info_);
}

void GameEngineImage::BitCopy(GameEngineImage* _Other)
{
	BitCopy(_Other, { 0,0 }, { 0, 0 }, _Other->GetScale());
}

void GameEngineImage::BitCopy(GameEngineImage* _Other, const float4& _CopyPos, const float4& _OtherPivot, const float4& _OtherPivotScale)
{
	// �����쿡�� �����ϴ� �Ϲ����� DC VS DC�� �����Լ�
	BitBlt(
		ImageDC_,  // �� DC�� �����ض�
		_CopyPos.ix(), // �� �̹����� X
		_CopyPos.iy(), // �� �̹����� Y �κп� �����ض�
		_OtherPivotScale.ix(), //  �� �̹����� �� ũ�⸸ŭ X
		_OtherPivotScale.iy(),	// �� �̹����� �� ũ�⸸ŭ Y
		_Other->ImageDC_, // �����Ϸ��� ����� DC
		_OtherPivot.ix(), // �����Ϸ��� ����� ������X
		_OtherPivot.iy(), // �����Ϸ��� ����� ������Y
		SRCCOPY  // �����϶�� ���
	);
}