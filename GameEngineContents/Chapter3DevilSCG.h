#pragma once
class Chapter3DevilSCG
{
public:
	//construcuter destructer
	Chapter3DevilSCG();
	~Chapter3DevilSCG();

	//delete Function
	Chapter3DevilSCG(const Chapter3DevilSCG& _Other) = delete;
	Chapter3DevilSCG(Chapter3DevilSCG&& _Other) noexcept = delete;
	Chapter3DevilSCG& operator=(const Chapter3DevilSCG& _Other) = delete;
	Chapter3DevilSCG& operator=(Chapter3DevilSCG&& _Other) noexcept = delete;
};

