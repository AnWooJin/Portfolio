#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>

class GameEngineLevel;
class GameEngineActor : public GameEngineNameObject
{
public:
	friend GameEngineLevel;

	//construcuter destructer
	GameEngineActor();
	virtual ~GameEngineActor();

	//delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

protected:
	// ������ �� ������ �ϰ� ������ �����ڿ����� ���� ���ϴ� �κ��� ����ϴ� �Լ�
	virtual void Start() = 0;
	// ���������� ������ ����� �� ȣ��Ǵ� �Լ�
	virtual void Update() {}
	// ���������� ������ ����� �� ������ �̹����� �׸��� �Լ�
	virtual void Render() {}

private:
	GameEngineLevel* Level_;
	float4 Position_;
	float4 Scale_;

	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}

};

