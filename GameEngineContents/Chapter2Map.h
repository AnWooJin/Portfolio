#pragma once
class Chapter2Map
{
public:
	//construcuter destructer
	Chapter2Map();
	~Chapter2Map();

	//delete Function
	Chapter2Map(const Chapter2Map& _Other) = delete;
	Chapter2Map(Chapter2Map&& _Other) noexcept = delete;
	Chapter2Map& operator=(const Chapter2Map& _Other) = delete;
	Chapter2Map& operator=(Chapter2Map&& _Other) noexcept = delete;
};

