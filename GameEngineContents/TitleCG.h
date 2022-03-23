#pragma once
#include <GameEngine/GameEngineActor.h>

class TitleCG : public GameEngineActor
{
public:
	//construcuter destructer
	TitleCG();
	~TitleCG();

	//delete Function
	TitleCG(const TitleCG& _Other) = delete;
	TitleCG(TitleCG&& _Other) noexcept = delete;
	TitleCG& operator=(const TitleCG& _Other) = delete;
	TitleCG& operator=(TitleCG&& _Other) noexcept = delete;

protected:

private:
	void Start() override;
	void Render() override;
};

