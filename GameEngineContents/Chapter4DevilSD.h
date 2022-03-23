#pragma once
class Chapter4DevilSD
{
public:
	//construcuter destructer
	Chapter4DevilSD();
	~Chapter4DevilSD();

	//delete Function
	Chapter4DevilSD(const Chapter4DevilSD& _Other) = delete;
	Chapter4DevilSD(Chapter4DevilSD&& _Other) noexcept = delete;
	Chapter4DevilSD& operator=(const Chapter4DevilSD& _Other) = delete;
	Chapter4DevilSD& operator=(Chapter4DevilSD&& _Other) noexcept = delete;
};

