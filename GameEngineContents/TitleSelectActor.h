#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineRenderer;
class TitleSelectActor : public GameEngineActor
{
public:
	//construcuter destructer
	TitleSelectActor();
	~TitleSelectActor();

	//delete Function
	TitleSelectActor(const TitleSelectActor& _Other) = delete;
	TitleSelectActor(TitleSelectActor&& _Other) noexcept = delete;
	TitleSelectActor& operator=(const TitleSelectActor& _Other) = delete;
	TitleSelectActor& operator=(TitleSelectActor&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* SelectRenderer0_;
	GameEngineRenderer* SelectRenderer1_;

	bool IsSelected_;

	void Start() override;
	void Update() override;
	void Render() override {};
	void TitleImageChange();
};

