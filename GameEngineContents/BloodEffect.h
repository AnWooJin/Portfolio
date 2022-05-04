#pragma once
#include <GameEngine/GameEngineActor.h>

class BloodEffect : public GameEngineActor
{
public:
	//construcuter destructer
	BloodEffect();
	~BloodEffect();

	//delete Function
	BloodEffect(const BloodEffect& _Other) = delete;
	BloodEffect(BloodEffect&& _Other) noexcept = delete;
	BloodEffect& operator=(const BloodEffect& _Other) = delete;
	BloodEffect& operator=(BloodEffect&& _Other) noexcept = delete;

protected:


private:
	void Start() override;
	void Update() override;
	void Render() override {};
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
};

