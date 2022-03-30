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
	// window에서 할당한 것들은 릭으로 체크가 안되지만 
	// 지워주는게 좋다
	// 윈도우에서 할당한 것들은 윈도우의 함수를 이용해서 지워준다.

	if (nullptr != BitMap_)
	{
		DeleteObject(BitMap_);
		BitMap_ = nullptr;
	}

	if (nullptr != OldBitMap_)
	{
		DeleteObject(OldBitMap_);
		OldBitMap_ = nullptr;
	}

	if (nullptr != ImageDC_)
	{
		DeleteDC(ImageDC_);
		ImageDC_ = nullptr;
	}
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

bool GameEngineImage::Load(const std::string& _Path)
{
	BitMap_ = static_cast<HBITMAP>(LoadImageA(
		nullptr,
		_Path.c_str(),
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE
	));

	if (nullptr == BitMap_)
	{
		MsgBoxAssertString(_Path + "이미지 로드에 실패했습니다. 여러분들이 살펴봐야할 문제 1. 경로는 제대로 됐나요? 2. 디버깅은 제대로 봤나요");
	}

	ImageDC_ = CreateCompatibleDC(nullptr);

	if (nullptr == BitMap_)
	{
		MsgBoxAssert("ImageDC 생성에 실패했습니다");
	}

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


////////////////////////////////////////////////////////BitBlt

void GameEngineImage::BitCopy(GameEngineImage* _Other, const float4& _CopyPos)
{
	BitCopy(_Other, _CopyPos, _Other->GetScale(), float4{ 0,0 });
}

void GameEngineImage::BitCopyCenter(GameEngineImage* _Other, const float4& _CopyPos)
{
	BitCopy(_Other, _CopyPos - _Other->GetScale().Half(), _Other->GetScale(), float4{ 0,0 });
}

void GameEngineImage::BitCopyCenterPivot(GameEngineImage* _Other, const float4& _CopyPos, const float4& _CopyPivot)
{
	BitCopy(_Other, _CopyPos - _Other->GetScale().Half() + _CopyPivot, float4{ 0,0 }, _Other->GetScale());
}

void GameEngineImage::BitCopyBot(GameEngineImage* _Other, const float4& _CopyPos)
{
	float4 ImagePivot = _Other->GetScale().Half();
	ImagePivot.y = _Other->GetScale().y;

	BitCopy(_Other, _CopyPos - ImagePivot, _Other->GetScale(), float4{ 0,0 });
}

void GameEngineImage::BitCopyBotPivot(GameEngineImage* _Other, const float4& _CopyPos, const float4& _CopyPivot)
{
	float4 ImagePivot = _Other->GetScale().Half();
	ImagePivot.y = _Other->GetScale().y;

	BitCopy(_Other, _CopyPos - ImagePivot + _CopyPivot, _Other->GetScale(), float4{ 0,0 });
}

void GameEngineImage::BitCopy(GameEngineImage* _Other)
{
	BitCopy(_Other, { 0,0 }, _Other->GetScale(), { 0,0 });
}

void GameEngineImage::BitCopy(GameEngineImage* _Other, const float4& _CopyPos, const float4& _CopyScale, const float4& _OtherPivot)
{
	// 윈도우에서 지원하는 일반적인 DC VS DC의 복사함수
	BitBlt(
		ImageDC_,  // 이 DC에 복사해라
		_CopyPos.ix(), // 내 이미지의 X
		_CopyPos.iy(), // 내 이미지의 Y 부분에 복사해라
		_CopyScale.ix(), //  내 이미지의 이 크기만큼 X
		_CopyScale.iy(),	// 내 이미지의 이 크기만큼 Y
		_Other->ImageDC_, // 복사하려는 대상의 DC
		_OtherPivot.ix(), // 복사하려는 대상의 시작점X
		_OtherPivot.iy(), // 복사하려는 대상의 시작점Y
		SRCCOPY  // 복사하라는 명령
	);
}

//////////////////////////////////////////////////////////////////trans


void GameEngineImage::TransCopy(GameEngineImage* _Other, const float4& _CopyPos, 
	const float4& _CopyScale, 
	const float4& _OtherPivot, const float4& _OtherScale, unsigned int _TransColor)
{
	// 윈도우에서 지원하는 일반적인 DC VS DC의 복사함수
	TransparentBlt(
		ImageDC_,  // 이 DC에 복사해라
		_CopyPos.ix(), // 내 이미지의 X
		_CopyPos.iy(), // 내 이미지의 Y 부분에 복사해라
		_CopyScale.ix(), //  내 이미지의 이 크기만큼 X
		_CopyScale.iy(),	// 내 이미지의 이 크기만큼 Y
		_Other->ImageDC_, // 복사하려는 대상의 DC
		_OtherPivot.ix(), // 복사하려는 대상의 시작점X
		_OtherPivot.iy(), // 복사하려는 대상의 시작점Y
		_OtherScale.ix(), // 복사하려는 대상의 이미지 크기 X
		_OtherScale.iy(), // 복사하려는 대상의 이미지 크기 Y
		_TransColor  // 복사하라는 명령
	);
}

void GameEngineImage::CutCount(int _x, int _y)
{
	float4 Scale = { GetScale().x / _x, GetScale().y / _y };
	Cut(Scale);
}

void GameEngineImage::Cut(const float4& _CutScale)
{
	if (0 != (GetScale().ix() % _CutScale.ix()))
	{
		MsgBoxAssert("자를수 있는 수치가 딱 맞아떨어지지 않습니다.");
	}

	if (0 != (GetScale().iy() % _CutScale.iy()))
	{
		MsgBoxAssert("자를수 있는 수치가 딱 맞아떨어지지 않습니다.");
	}

	int XCount = GetScale().ix() / _CutScale.ix();
	int YCount = GetScale().iy() / _CutScale.iy();

	for (int y = 0; y < YCount ; y++)
	{
		for (int x = 0; x < XCount; x++)
		{
			CutPivot_.push_back({ static_cast<float>(x * _CutScale.ix()), static_cast<float>(y * _CutScale.iy()) });
			CutScale_.push_back(_CutScale);
		}
	}
}

int GameEngineImage::GetImagePixel(int _x, int _y)
{
	return GetPixel(ImageDC_, _x, _y);
}