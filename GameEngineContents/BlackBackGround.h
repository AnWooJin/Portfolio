#pragma once
#include <GameEngine/GameEngineActor.h>

class BlackBackGround : public GameEngineActor
{
public:
	//construcuter destructer
	BlackBackGround();
	~BlackBackGround();

	//delete Function
	BlackBackGround(const BlackBackGround& _Other) = delete;
	BlackBackGround(BlackBackGround&& _Other) noexcept = delete;
	BlackBackGround& operator=(const BlackBackGround& _Other) = delete;
	BlackBackGround& operator=(BlackBackGround&& _Other) noexcept = delete;

protected:

private:
	void Start() override;
	void Update() override {};
	void Render() override {};
};

