#pragma once
class Chapter5DevilSCG
{
public:
	//construcuter destructer
	Chapter5DevilSCG();
	~Chapter5DevilSCG();

	//delete Function
	Chapter5DevilSCG(const Chapter5DevilSCG& _Other) = delete;
	Chapter5DevilSCG(Chapter5DevilSCG&& _Other) noexcept = delete;
	Chapter5DevilSCG& operator=(const Chapter5DevilSCG& _Other) = delete;
	Chapter5DevilSCG& operator=(Chapter5DevilSCG&& _Other) noexcept = delete;
};

