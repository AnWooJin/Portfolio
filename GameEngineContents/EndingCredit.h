#pragma once
class EndingCredit
{
public:
	//construcuter destructer
	EndingCredit();
	~EndingCredit();

	//delete Function
	EndingCredit(const EndingCredit& _Other) = delete;
	EndingCredit(EndingCredit&& _Other) noexcept = delete;
	EndingCredit& operator=(const EndingCredit& _Other) = delete;
	EndingCredit& operator=(EndingCredit&& _Other) noexcept = delete;

protected:

private:

};

