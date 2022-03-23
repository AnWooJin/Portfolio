#pragma once
class Chapter3DevilSD
{
public:
	//construcuter destructer
	Chapter3DevilSD();
	~Chapter3DevilSD();

	//delete Function
	Chapter3DevilSD(const Chapter3DevilSD& _Other) = delete;
	Chapter3DevilSD(Chapter3DevilSD&& _Other) noexcept = delete;
	Chapter3DevilSD& operator=(const Chapter3DevilSD& _Other) = delete;
	Chapter3DevilSD& operator=(Chapter3DevilSD&& _Other) noexcept = delete;
};

