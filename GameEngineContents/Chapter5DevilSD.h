#pragma once
class Chapter5DevilSD
{
public:
	//construcuter destructer
	Chapter5DevilSD();
	~Chapter5DevilSD();

	//delete Function
	Chapter5DevilSD(const Chapter5DevilSD& _Other) = delete;
	Chapter5DevilSD(Chapter5DevilSD&& _Other) noexcept = delete;
	Chapter5DevilSD& operator=(const Chapter5DevilSD& _Other) = delete;
	Chapter5DevilSD& operator=(Chapter5DevilSD&& _Other) noexcept = delete;
};

