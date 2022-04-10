#pragma once
#include <GameEngine/GameEngineActor.h>

class DevilSD : public GameEngineActor
{
public:
	//construcuter destructer
	DevilSD();
	DevilSD(int _Level);
	~DevilSD();

	//delete Function
	DevilSD(const DevilSD& _Other) = delete;
	DevilSD(DevilSD&& _Other) noexcept = delete;
	DevilSD& operator=(const DevilSD& _Other) = delete;
	DevilSD& operator=(DevilSD&& _Other) noexcept = delete;

protected:

private:
	int ChapterLevel_;

	void Start() override;
	void Update() override;
	void Render() override;

	void ImageSetting(int _ChapterLevel);
};

