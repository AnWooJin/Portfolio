#pragma once
#include "GameEngineNameObject.h"
#include "ThirdParty/inc/fmod.hpp"
#include <map>

class GameEngineSoundPlayer;
class GameEngineSound : public GameEngineNameObject
{
public:
	//construcuter destructer
	GameEngineSound();
	~GameEngineSound();

	//delete Function
	GameEngineSound(const GameEngineSound& _Other) = delete;
	GameEngineSound(GameEngineSound&& _Other) noexcept = delete;
	GameEngineSound& operator=(const GameEngineSound& _Other) = delete;
	GameEngineSound& operator=(GameEngineSound&& _Other) noexcept = delete;

protected:
	bool Load(const std::string& _Path);

private:
	FMOD::Sound* Sound;

public:
	///////////////////////////////// 사운드 매니지먼트 기능

	static GameEngineSoundPlayer SoundPlayControl(const std::string& _Name);

	// 단순히 사운드를 딱 한번만 재생하는 함수
	static void SoundPlayOneShot(const std::string& _Name, int LoopCount = 0);
	static void Update();

	////////////////////////////////////  리소스 매니지먼트 기능
	
public:
	static GameEngineSound* FindRes(const std::string& _Name);
	static GameEngineSound* LoadRes(const std::string& _Path);
	static GameEngineSound* LoadRes(const std::string& _Path, const std::string& _Name);

	static void AllResourcesDestroy();

private:
	static std::map<std::string, GameEngineSound*> AllRes;

};

//////////  사운드를 재생하거나 제어하는 기능을 담당하는 클래스

class GameEngineSound;
class GameEngineSoundPlayer
{
	friend GameEngineSound;

public:
	void PlaySpeed(float _Speed);
	void Stop();
	void Volume(float _Value);

	GameEngineSoundPlayer(const GameEngineSoundPlayer& _Other);

private:
	GameEngineSound* Sound_;
	FMOD::Channel* ControlHandle_;

	GameEngineSoundPlayer(GameEngineSound* Sound, FMOD::Channel* ControlHandle);

public:
	GameEngineSoundPlayer();
	~GameEngineSoundPlayer();
};

