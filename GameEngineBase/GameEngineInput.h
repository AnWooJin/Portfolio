#pragma once
#include <Windows.h>
#include <map>
#include <string>



class GameEngineInput
{

private:
	class GameEngineKey
	{
		friend GameEngineInput;

		bool Down_; // 처음 키를 눌렀을 때
		bool Press_; // 키를 계속 누르고 있을 때
		bool Up_; // 키를 누르고 땠을때
		bool Free_; // 아무 키도 누르고 있지 않을 때

		float Time_;
		int Key_;

		bool KeyCheck()
		{
			return 0 != GetAsyncKeyState(Key_);
		}

		void Update(float _DeltaTime);

		// 어떤 한 키도 누르지 않은 상태를 만드는 함수
		void Reset()
		{
			Down_ = false;
			Press_ = false;
			Up_ = false;
			Free_ = true;
		}
	};

private:
	static GameEngineInput* Inst_;

public:
	static GameEngineInput* GetInst()
	{
		return Inst_;
	}

	static void Destroy()
	{
		if (nullptr != Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}

public:
	void Update(float _DetaTime = 0.0f);
	void CreateKey(const std::string& _Name, int _Key);

	float GetTime(const std::string& _Name);
	bool IsDown(const std::string& _Name);
	bool IsUp(const std::string& _Name);
	bool IsPress(const std::string& _Name);
	bool IsFree(const std::string& _Name);
	bool IsKey(const std::string& _Name);

protected:

private:
	std::map<std::string, GameEngineKey> AllInputKey_;

	//construcuter destructer
	GameEngineInput();
	~GameEngineInput();

	//delete Function
	GameEngineInput(const GameEngineInput& _Other) = delete;
	GameEngineInput(GameEngineInput&& _Other) noexcept = delete;
	GameEngineInput& operator=(const GameEngineInput& _Other) = delete;
	GameEngineInput& operator=(GameEngineInput&& _Other) noexcept = delete;
};

