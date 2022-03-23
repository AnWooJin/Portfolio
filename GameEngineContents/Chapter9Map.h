#pragma once
class Chapter9Map
{
public:
	//construcuter destructer
	Chapter9Map();
	~Chapter9Map();

	//delete Function
	Chapter9Map(const Chapter9Map& _Other) = delete;
	Chapter9Map(Chapter9Map&& _Other) noexcept = delete;
	Chapter9Map& operator=(const Chapter9Map& _Other) = delete;
	Chapter9Map& operator=(Chapter9Map&& _Other) noexcept = delete;
};

