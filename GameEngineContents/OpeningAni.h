#pragma once
class OpeningAni
{
public:
	//construcuter destructer
	OpeningAni();
	~OpeningAni();

	//delete Function
	OpeningAni(const OpeningAni& _Other) = delete;
	OpeningAni(OpeningAni&& _Other) noexcept = delete;
	OpeningAni& operator=(const OpeningAni& _Other) = delete;
	OpeningAni& operator=(OpeningAni&& _Other) noexcept = delete;
};

