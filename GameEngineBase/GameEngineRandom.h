#pragma once
#include <random>
// 제네레이터와 
// Uniform 규격으로 나뉘어
// 각각 클래스가 있다.
// 제네레이터는 숫자를 메르헨 트위스터 알고리즘을 이용해 비트를 뒤섞는 클래스이고
// 유니폼은 제네레이터에서 나온 값의 최소, 최대를 설정하여 제한을 거는 클래스이다.
class GameEngineRandom
{
private:
	std::mt19937_64 mt_;

public:
	
	//반환하는 수가 실수냐 정수냐에 따라 생성기가 달라진다.
	int RandomInt(int _Min, int _Max)
	{
		std::uniform_int_distribution<int>Uniform(_Min, _Max);
		return Uniform(mt_);
	}

	
	float RandomFloat(float _Min, float _Max)
	{
		std::uniform_real_distribution<float>Uniform(_Min, _Max);
		return Uniform(mt_);
	}
public:
	//construcuter destructer
	GameEngineRandom();
	~GameEngineRandom();

	//delete Function
	GameEngineRandom(const GameEngineRandom& _Other) = delete;
	GameEngineRandom(GameEngineRandom&& _Other) noexcept = delete;
	GameEngineRandom& operator=(const GameEngineRandom& _Other) = delete;
	GameEngineRandom& operator=(GameEngineRandom&& _Other) noexcept = delete;
};

