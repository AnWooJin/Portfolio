#pragma once
class Chapter3Map
{
public:
	//construcuter destructer
	Chapter3Map();
	~Chapter3Map();

	//delete Function
	Chapter3Map(const Chapter3Map& _Other) = delete;
	Chapter3Map(Chapter3Map&& _Other) noexcept = delete;
	Chapter3Map& operator=(const Chapter3Map& _Other) = delete;
	Chapter3Map& operator=(Chapter3Map&& _Other) noexcept = delete;
};

