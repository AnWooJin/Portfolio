#pragma once
class Chapter7DevilSD
{
public:
	//construcuter destructer
	Chapter7DevilSD();
	~Chapter7DevilSD();

	//delete Function
	Chapter7DevilSD(const Chapter7DevilSD& _Other) = delete;
	Chapter7DevilSD(Chapter7DevilSD&& _Other) noexcept = delete;
	Chapter7DevilSD& operator=(const Chapter7DevilSD& _Other) = delete;
	Chapter7DevilSD& operator=(Chapter7DevilSD&& _Other) noexcept = delete;
};

