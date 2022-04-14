#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineRenderer;
class PrologueScene : public GameEngineActor
{
public:
	//construcuter destructer
	PrologueScene();
	~PrologueScene();

	//delete Function
	PrologueScene(const PrologueScene& _Other) = delete;
	PrologueScene(PrologueScene&& _Other) noexcept = delete;
	PrologueScene& operator=(const PrologueScene& _Other) = delete;
	PrologueScene& operator=(PrologueScene&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* MyRenderer_;

	void Start() override;
	void Update() override;
	void Render() override {};
};

