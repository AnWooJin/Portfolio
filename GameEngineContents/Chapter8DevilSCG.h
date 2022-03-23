#pragma once
class Chapter8DevilSCG
{
public:
	//construcuter destructer
	Chapter8DevilSCG();
	~Chapter8DevilSCG();

	//delete Function
	Chapter8DevilSCG(const Chapter8DevilSCG& _Other) = delete;
	Chapter8DevilSCG(Chapter8DevilSCG&& _Other) noexcept = delete;
	Chapter8DevilSCG& operator=(const Chapter8DevilSCG& _Other) = delete;
	Chapter8DevilSCG& operator=(Chapter8DevilSCG&& _Other) noexcept = delete;
};

