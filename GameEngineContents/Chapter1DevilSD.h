#pragma once
class Chapter1DevilSD
{
public:
	//construcuter destructer
	Chapter1DevilSD();
	~Chapter1DevilSD();

	//delete Function
	Chapter1DevilSD(const Chapter1DevilSD& _Other) = delete;
	Chapter1DevilSD(Chapter1DevilSD&& _Other) noexcept = delete;
	Chapter1DevilSD& operator=(const Chapter1DevilSD& _Other) = delete;
	Chapter1DevilSD& operator=(Chapter1DevilSD&& _Other) noexcept = delete;
};

