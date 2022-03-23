#pragma once
class Chapter2DevilSD
{
public:
	//construcuter destructer
	Chapter2DevilSD();
	~Chapter2DevilSD();

	//delete Function
	Chapter2DevilSD(const Chapter2DevilSD& _Other) = delete;
	Chapter2DevilSD(Chapter2DevilSD&& _Other) noexcept = delete;
	Chapter2DevilSD& operator=(const Chapter2DevilSD& _Other) = delete;
	Chapter2DevilSD& operator=(Chapter2DevilSD&& _Other) noexcept = delete;
};

