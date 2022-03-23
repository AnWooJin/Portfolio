#pragma once
class Chapter5Map
{
public:
	//construcuter destructer
	Chapter5Map();
	~Chapter5Map();

	//delete Function
	Chapter5Map(const Chapter5Map& _Other) = delete;
	Chapter5Map(Chapter5Map&& _Other) noexcept = delete;
	Chapter5Map& operator=(const Chapter5Map& _Other) = delete;
	Chapter5Map& operator=(Chapter5Map&& _Other) noexcept = delete;
};

