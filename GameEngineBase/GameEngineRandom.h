#pragma once
#include <random>
// ���׷����Ϳ� 
// Uniform �԰����� ������
// ���� Ŭ������ �ִ�.
// ���׷����ʹ� ���ڸ� �޸��� Ʈ������ �˰����� �̿��� ��Ʈ�� �ڼ��� Ŭ�����̰�
// �������� ���׷����Ϳ��� ���� ���� �ּ�, �ִ븦 �����Ͽ� ������ �Ŵ� Ŭ�����̴�.
class GameEngineRandom
{
private:
	std::mt19937_64 mt_;

public:
	
	//��ȯ�ϴ� ���� �Ǽ��� �����Ŀ� ���� �����Ⱑ �޶�����.
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

