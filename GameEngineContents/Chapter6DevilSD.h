#pragma once
class Chapter6DevilSD
{
public:
	//construcuter destructer
	Chapter6DevilSD();
	~Chapter6DevilSD();

	//delete Function
	Chapter6DevilSD(const Chapter6DevilSD& _Other) = delete;
	Chapter6DevilSD(Chapter6DevilSD&& _Other) noexcept = delete;
	Chapter6DevilSD& operator=(const Chapter6DevilSD& _Other) = delete;
	Chapter6DevilSD& operator=(Chapter6DevilSD&& _Other) noexcept = delete;
};

