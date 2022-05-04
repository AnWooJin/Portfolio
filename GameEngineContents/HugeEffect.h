#pragma once
#include <GameEngine/GameEngineActor.h>

class HugeEffect : public GameEngineActor
{
public:
	//construcuter destructer
	HugeEffect();
	~HugeEffect();

	//delete Function
	HugeEffect(const HugeEffect& _Other) = delete;
	HugeEffect(HugeEffect&& _Other) noexcept = delete;
	HugeEffect& operator=(const HugeEffect& _Other) = delete;
	HugeEffect& operator=(HugeEffect&& _Other) noexcept = delete;


private:
	void Start() override;
	void Update() override;
	void Render() override {};
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
};

