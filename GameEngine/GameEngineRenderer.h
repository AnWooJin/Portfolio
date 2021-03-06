#pragma once
#include "GameEngineActorSubObject.h"
#include "GameEngineEnum.h"
#include <map>

class GameEngineImage;
class GameEngineFolderImage;
class GameEngineRenderer : public GameEngineActorSubObject
{
	friend GameEngineActor;
	friend GameEngineLevel;

public:
	//construcuter destructer
	GameEngineRenderer();
	~GameEngineRenderer();

	//delete Function
	GameEngineRenderer(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer(GameEngineRenderer&& _Other) noexcept = delete;
	GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

	inline void SetTransColor(unsigned int _Color)
	{
		TransColor_ = _Color;
	}

	inline void SetPivot(const float4& _Pos)
	{
		RenderPivot_ = _Pos;
	}


	inline void SetPivotType(const RenderPivot& _Type)
	{
		PivotType_ = _Type;
	}

	inline void SetScaleMode(const RenderScaleMode& _Mode)
	{
		ScaleMode_ = _Mode;
	}

	// 랜더 스케일(화면에 그려지는 크기)와 이미지 스케일(이미지에서 그릴 부분을 잘라오는 크기)를 같이 맞춰준다.
	void SetImageScale();

	inline void SetScale(const float4& _Scale)
	{
		ScaleMode_ = RenderScaleMode::User;
		RenderScale_ = _Scale;
	}
	inline void SetAlpha(unsigned int _Alpha)
	{
		Alpha_ = _Alpha;

		if (Alpha_ >= 255)
		{
			Alpha_ = 255;
		}
	}
	inline float4 GetScale()
	{
		return RenderScale_;
	}

	inline float4 GetImagePivot()
	{
		return RenderImagePivot_;
	}

	inline float4 GetImageScale()
	{
		return RenderImageScale_;
	}

	inline float4 GetSortingPivot()
	{
		return GetActor()->GetPosition() + RenderPivot_ + SortingPivot;
	}


	inline float4 GetPivot()
	{
		return RenderPivot_;
	}

	inline GameEngineImage* GetImage()
	{
		return Image_;
	}


	void CameraEffectOff()
	{
		IsCameraEffect_ = false;
	}

	void CameraEffectOn()
	{
		IsCameraEffect_ = true;
	}

	void SetPause(bool _Value)
	{
		Pause_ = _Value;
	}

	void PauseOn()
	{
		Pause_ = true;
	}

	void PauseOff()
	{
		Pause_ = false;
	}

	void PauseSwitch()
	{
		Pause_ = !Pause_;
	}
	void SetImage(const std::string& _Name);

	void SetImageAnimationReset(const std::string& _Name);

	void SetIndex(size_t _Index, float4 _Scale = {-1.0f, -1.0f});


	void SetOrder(int _Order) override;

protected:
	void Render();

private:
	friend class FrameAnimation;

	
	GameEngineImage* Image_;
	RenderPivot PivotType_; // CENTER, BOT
	RenderScaleMode ScaleMode_; 

	// 화면에 그려지는 좌표
	float4 RenderPivot_;
	// 화면에 그려지는 크기
	float4 RenderScale_;

	// 이미지에서 잘라내는 크기
	float4 RenderImageScale_; // 복사받으려는 이미지의 크기
	float4 RenderImagePivot_; // 복사받으려는 이미지를 잘라오는 시작 좌표

	float4 SortingPivot;	// 복사받으려는 이미지 한칸의 크기

	unsigned int TransColor_;
	unsigned int Alpha_;

	bool IsCameraEffect_;
	bool Pause_;

////////////////////////   회전용 트랜스 이미지

	float RotZ_;
	GameEngineImage* RotationFilterImage_;

public:
	void SetRotationFilter(const std::string& _ImageName);

	void SetRotationZ(float _RotZ)
	{
		RotZ_ = _RotZ;
		Alpha_ = 255;
	}


////////////////////////////////////////////////////////////// 애니메이션

private:
	class FrameAnimation : public GameEngineNameObject
	{
	private:
		friend GameEngineRenderer;

		GameEngineRenderer* Renderer_;
		GameEngineImage* Image_;
		GameEngineFolderImage* FolderImage_;
		int TimeKey;
		int CurrentFrame_;
		int StartFrame_;
		int EndFrame_;
		float CurrentInterTime_;
		float InterTime_;
		bool Loop_ = false;
		bool IsEnd;

	public:
		inline int WorldCurrentFrame() const
		{
			return CurrentFrame_;
		}

		inline int WorldStartFrame() const
		{
			return StartFrame_;
		}

		inline int WorldEndFrame() const
		{
			return EndFrame_;
		}

		inline int LoopCurrentFrame() const
		{
			return StartFrame_ - CurrentFrame_;
		}

	public:
		FrameAnimation()
			: Image_(nullptr),
			Renderer_(nullptr),
			FolderImage_(nullptr),
			CurrentFrame_(-1),
			StartFrame_(-1),
			EndFrame_(-1),
			CurrentInterTime_(0.1f),
			InterTime_(0.1f),
			Loop_(true),
			IsEnd(false),
			TimeKey(0)
		{
		}

	public:
		void Update();

		void Reset()
		{
			IsEnd = false;
			CurrentFrame_ = StartFrame_;
			CurrentInterTime_ = InterTime_;
		}
	};

public:
	void CreateAnimation(const std::string& _Image, const std::string& _Name, int _StartIndex, int _EndIndex, float _InterTime, bool _Loop = true);
	void CreateFolderAnimation(const std::string& _Image, const std::string& _Name, int _StartIndex, int _EndIndex, float _InterTime, bool _Loop = true);

	void CreateFolderAnimationTimeKey(const std::string& _Image, const std::string& _Name, int _TimeScaleKey , int _StartIndex, int _EndIndex, float _InterTime, bool _Loop = true);
	void ChangeAnimation(const std::string& _Name);

	bool IsEndAnimation();

	bool IsAnimationName(const std::string& _Name);

	const FrameAnimation* FindAnimation(const std::string& _Name);

	inline const FrameAnimation* CurrentAnimation()
	{
		return CurrentAnimation_;
	}

private:
	std::map<std::string, FrameAnimation> Animations_;
	FrameAnimation* CurrentAnimation_;
};


