#pragma once
class Chapter2DevilSCG
{
public:
	//construcuter destructer
	Chapter2DevilSCG();
	~Chapter2DevilSCG();

	//delete Function
	Chapter2DevilSCG(const Chapter2DevilSCG& _Other) = delete;
	Chapter2DevilSCG(Chapter2DevilSCG&& _Other) noexcept = delete;
	Chapter2DevilSCG& operator=(const Chapter2DevilSCG& _Other) = delete;
	Chapter2DevilSCG& operator=(Chapter2DevilSCG&& _Other) noexcept = delete;
};

