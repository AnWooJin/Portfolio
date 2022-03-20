#pragma once
class Demon
{
public:
	//construcuter destructer
	Demon();
	~Demon();

	//delete Function
	Demon(const Demon& _Other) = delete;
	Demon(Demon&& _Other) noexcept = delete;
	Demon& operator=(const Demon& _Other) = delete;
	Demon& operator=(Demon&& _Other) noexcept = delete;

protected:


private:

};

