#pragma once
#include <GameEngine/GameEngineActor.h>

class HitEffect : public GameEngineActor
{
public:
	//construcuter destructer
	HitEffect();
	~HitEffect();

	//delete Function
	HitEffect(const HitEffect& _Other) = delete;
	HitEffect(HitEffect&& _Other) noexcept = delete;
	HitEffect& operator=(const HitEffect& _Other) = delete;
	HitEffect& operator=(HitEffect&& _Other) noexcept = delete;

protected:

private:
	void Start() override;
	void Update() override;
	void Render() override {};
	void LevelChangeStart(GameEngineLevel* _PrevLevel);
};

