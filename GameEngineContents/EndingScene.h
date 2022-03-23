#pragma once
class EndingScene
{
public:
	//construcuter destructer
	EndingScene();
	~EndingScene();

	//delete Function
	EndingScene(const EndingScene& _Other) = delete;
	EndingScene(EndingScene&& _Other) noexcept = delete;
	EndingScene& operator=(const EndingScene& _Other) = delete;
	EndingScene& operator=(EndingScene&& _Other) noexcept = delete;
};

