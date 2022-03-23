#pragma once
class Chapter4Map
{
public:
	//construcuter destructer
	Chapter4Map();
	~Chapter4Map();

	//delete Function
	Chapter4Map(const Chapter4Map& _Other) = delete;
	Chapter4Map(Chapter4Map&& _Other) noexcept = delete;
	Chapter4Map& operator=(const Chapter4Map& _Other) = delete;
	Chapter4Map& operator=(Chapter4Map&& _Other) noexcept = delete;
};

