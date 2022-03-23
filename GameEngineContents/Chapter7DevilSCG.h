#pragma once
class Chapter7DevilSCG
{
public:
	//construcuter destructer
	Chapter7DevilSCG();
	~Chapter7DevilSCG();

	//delete Function
	Chapter7DevilSCG(const Chapter7DevilSCG& _Other) = delete;
	Chapter7DevilSCG(Chapter7DevilSCG&& _Other) noexcept = delete;
	Chapter7DevilSCG& operator=(const Chapter7DevilSCG& _Other) = delete;
	Chapter7DevilSCG& operator=(Chapter7DevilSCG&& _Other) noexcept = delete;
};

