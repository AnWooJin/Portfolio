#pragma once
#include <GameEngine/GameEngineActor.h>
class MoveEffect : public GameEngineActor
{
public:
	//construcuter destructer
	MoveEffect();
	~MoveEffect();

	//delete Function
	MoveEffect(const MoveEffect& _Other) = delete;
	MoveEffect(MoveEffect&& _Other) noexcept = delete;
	MoveEffect& operator=(const MoveEffect& _Other) = delete;
	MoveEffect& operator=(MoveEffect&& _Other) noexcept = delete;

	float Time_;
protected:

private:
	void Start() override;
	void Update() override;
	void Render() override {};
};

