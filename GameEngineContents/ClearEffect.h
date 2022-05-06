#pragma once
#include <GameEngine/GameEngineActor.h>

class ClearEffect : public GameEngineActor
{
public:
	//construcuter destructer
	ClearEffect();
	~ClearEffect();

	//delete Function
	ClearEffect(const ClearEffect& _Other) = delete;
	ClearEffect(ClearEffect&& _Other) noexcept = delete;
	ClearEffect& operator=(const ClearEffect& _Other) = delete;
	ClearEffect& operator=(ClearEffect&& _Other) noexcept = delete;

protected:


private:
	void Start() override;
	void Update() override;
	void Render() override {};
};

