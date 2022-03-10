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

	// 그냥 std::string으로 하면 값이 복사가 되면서 문제가 생길 수 있기 때문에 &로 넣어준다.
	inline void SetName(const std::string& _Name)
	{
		Name_ = _Name;
	}

	// 상황에 따라 구분하여 사용한다
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

