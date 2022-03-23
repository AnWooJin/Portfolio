#pragma once
class Chapter4DevilSCG
{
public:
	//construcuter destructer
	Chapter4DevilSCG();
	~Chapter4DevilSCG();

	//delete Function
	Chapter4DevilSCG(const Chapter4DevilSCG& _Other) = delete;
	Chapter4DevilSCG(Chapter4DevilSCG&& _Other) noexcept = delete;
	Chapter4DevilSCG& operator=(const Chapter4DevilSCG& _Other) = delete;
	Chapter4DevilSCG& operator=(Chapter4DevilSCG&& _Other) noexcept = delete;
};

