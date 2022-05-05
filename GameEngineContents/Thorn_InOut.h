#pragma once
class Thorn_InOut
{
public:
	//construcuter destructer
	Thorn_InOut();
	~Thorn_InOut();

	//delete Function
	Thorn_InOut(const Thorn_InOut& _Other) = delete;
	Thorn_InOut(Thorn_InOut&& _Other) noexcept = delete;
	Thorn_InOut& operator=(const Thorn_InOut& _Other) = delete;
	Thorn_InOut& operator=(Thorn_InOut&& _Other) noexcept = delete;
};

