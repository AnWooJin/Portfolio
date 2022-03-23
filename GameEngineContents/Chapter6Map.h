#pragma once
class Chapter6Map
{
public:
	//construcuter destructer
	Chapter6Map();
	~Chapter6Map();

	//delete Function
	Chapter6Map(const Chapter6Map& _Other) = delete;
	Chapter6Map(Chapter6Map&& _Other) noexcept = delete;
	Chapter6Map& operator=(const Chapter6Map& _Other) = delete;
	Chapter6Map& operator=(Chapter6Map&& _Other) noexcept = delete;
};

