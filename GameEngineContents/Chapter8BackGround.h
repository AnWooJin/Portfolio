#pragma once
class Chapter8BackGround
{
public:
	//construcuter destructer
	Chapter8BackGround();
	~Chapter8BackGround();

	//delete Function
	Chapter8BackGround(const Chapter8BackGround& _Other) = delete;
	Chapter8BackGround(Chapter8BackGround&& _Other) noexcept = delete;
	Chapter8BackGround& operator=(const Chapter8BackGround& _Other) = delete;
	Chapter8BackGround& operator=(Chapter8BackGround&& _Other) noexcept = delete;
};

