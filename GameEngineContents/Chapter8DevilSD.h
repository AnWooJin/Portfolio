#pragma once
class Chapter8DevilSD
{
public:
	//construcuter destructer
	Chapter8DevilSD();
	~Chapter8DevilSD();

	//delete Function
	Chapter8DevilSD(const Chapter8DevilSD& _Other) = delete;
	Chapter8DevilSD(Chapter8DevilSD&& _Other) noexcept = delete;
	Chapter8DevilSD& operator=(const Chapter8DevilSD& _Other) = delete;
	Chapter8DevilSD& operator=(Chapter8DevilSD&& _Other) noexcept = delete;
};

