#pragma once
class Chapter8ExtraSCG
{
public:
	//construcuter destructer
	Chapter8ExtraSCG();
	~Chapter8ExtraSCG();

	//delete Function
	Chapter8ExtraSCG(const Chapter8ExtraSCG& _Other) = delete;
	Chapter8ExtraSCG(Chapter8ExtraSCG&& _Other) noexcept = delete;
	Chapter8ExtraSCG& operator=(const Chapter8ExtraSCG& _Other) = delete;
	Chapter8ExtraSCG& operator=(Chapter8ExtraSCG&& _Other) noexcept = delete;
};

