#pragma once
#include <GameEngine/GameEngineActor.h>

class BackGroundMap : public GameEngineActor
{
public:
	//construcuter destructer
	BackGroundMap();
	BackGroundMap(int _Level);
	~BackGroundMap();

	//delete Function
	BackGroundMap(const BackGroundMap& _Other) = delete;
	BackGroundMap(BackGroundMap&& _Other) noexcept = delete;
	BackGroundMap& operator=(const BackGroundMap& _Other) = delete;
	BackGroundMap& operator=(BackGroundMap&& _Other) noexcept = delete;

protected:

private:
	int ChapterLevel_;

	void Start() override;
	void Render() override;

	void MapSetting(int _Level);
};

