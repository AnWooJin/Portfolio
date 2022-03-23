#pragma once
class Chapter6DevilSCG
{
public:
	//construcuter destructer
	Chapter6DevilSCG();
	~Chapter6DevilSCG();

	//delete Function
	Chapter6DevilSCG(const Chapter6DevilSCG& _Other) = delete;
	Chapter6DevilSCG(Chapter6DevilSCG&& _Other) noexcept = delete;
	Chapter6DevilSCG& operator=(const Chapter6DevilSCG& _Other) = delete;
	Chapter6DevilSCG& operator=(Chapter6DevilSCG&& _Other) noexcept = delete;
};

