#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRenderer.h>

class BackGroundMap : public GameEngineActor
{
public:
	//construcuter destructer
	BackGroundMap();
	~BackGroundMap();

	//delete Function
	BackGroundMap(const BackGroundMap& _Other) = delete;
	BackGroundMap(BackGroundMap&& _Other) noexcept = delete;
	BackGroundMap& operator=(const BackGroundMap& _Other) = delete;
	BackGroundMap& operator=(BackGroundMap&& _Other) noexcept = delete;

	void MapSetting(int _Level);
protected:

private:
	GameEngineRenderer* MapRenderer_;
	void Start() override;
	void Render() override;

	
};

