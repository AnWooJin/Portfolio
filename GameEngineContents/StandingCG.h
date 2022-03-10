#pragma once
class StandingCG
{
public:
	//construcuter destructer
	StandingCG();
	~StandingCG();

	//delete Function
	StandingCG(const StandingCG& _Other) = delete;
	StandingCG(StandingCG&& _Other) noexcept = delete;
	StandingCG& operator=(const StandingCG& _Other) = delete;
	StandingCG& operator=(StandingCG&& _Other) noexcept = delete;

protected:

private:

};

