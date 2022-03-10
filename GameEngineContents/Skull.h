#pragma once
class Skull
{
public:
	//construcuter destructer
	Skull();
	~Skull();

	//delete Function
	Skull(const Skull& _Other) = delete;
	Skull(Skull&& _Other) noexcept = delete;
	Skull& operator=(const Skull& _Other) = delete;
	Skull& operator=(Skull&& _Other) noexcept = delete;

protected:

private:

};

