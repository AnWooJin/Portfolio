#pragma once
class Chapter7Map
{
public:
	//construcuter destructer
	Chapter7Map();
	~Chapter7Map();

	//delete Function
	Chapter7Map(const Chapter7Map& _Other) = delete;
	Chapter7Map(Chapter7Map&& _Other) noexcept = delete;
	Chapter7Map& operator=(const Chapter7Map& _Other) = delete;
	Chapter7Map& operator=(Chapter7Map&& _Other) noexcept = delete;
};

