#pragma once
class Chapter1DevilSCG
{
public:
	//construcuter destructer
	Chapter1DevilSCG();
	~Chapter1DevilSCG();

	//delete Function
	Chapter1DevilSCG(const Chapter1DevilSCG& _Other) = delete;
	Chapter1DevilSCG(Chapter1DevilSCG&& _Other) noexcept = delete;
	Chapter1DevilSCG& operator=(const Chapter1DevilSCG& _Other) = delete;
	Chapter1DevilSCG& operator=(Chapter1DevilSCG&& _Other) noexcept = delete;
};

