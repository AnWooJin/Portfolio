#pragma once
class Chapter1Map
{
public:
	//construcuter destructer
	Chapter1Map();
	~Chapter1Map();

	//delete Function
	Chapter1Map(const Chapter1Map& _Other) = delete;
	Chapter1Map(Chapter1Map&& _Other) noexcept = delete;
	Chapter1Map& operator=(const Chapter1Map& _Other) = delete;
	Chapter1Map& operator=(Chapter1Map&& _Other) noexcept = delete;
};

