#pragma once
class Chapter8Map
{
public:
	//construcuter destructer
	Chapter8Map();
	~Chapter8Map();

	//delete Function
	Chapter8Map(const Chapter8Map& _Other) = delete;
	Chapter8Map(Chapter8Map&& _Other) noexcept = delete;
	Chapter8Map& operator=(const Chapter8Map& _Other) = delete;
	Chapter8Map& operator=(Chapter8Map&& _Other) noexcept = delete;
};

