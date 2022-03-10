#pragma once
#include <string>


class GameEngineNameObject
{
public:
	//construcuter destructer
	GameEngineNameObject();
	virtual ~GameEngineNameObject();

	//delete Function
	GameEngineNameObject(const GameEngineNameObject& _Other) = delete;
	GameEngineNameObject(GameEngineNameObject&& _Other) noexcept = delete;
	GameEngineNameObject& operator=(const GameEngineNameObject& _Other) = delete;
	GameEngineNameObject& operator=(GameEngineNameObject&& _Other) noexcept = delete;

	// �׳� std::string���� �ϸ� ���� ���簡 �Ǹ鼭 ������ ���� �� �ֱ� ������ &�� �־��ش�.
	inline void SetName(const std::string& _Name)
	{
		Name_ = _Name;
	}

	// ��Ȳ�� ���� �����Ͽ� ����Ѵ�
	std::string GetNameCopy()
	{
		return Name_;
	}

	const std::string& GetNameConstRef()
	{
		return Name_;
	}

	const char* GetNameConstPtr()
	{
		return Name_.c_str();
	}

protected:

private:
	std::string Name_;
};

