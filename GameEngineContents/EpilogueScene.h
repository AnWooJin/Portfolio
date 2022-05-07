#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineRenderer;
class EpilogueScene : public GameEngineActor
{
public:
	//construcuter destructer
	EpilogueScene();
	~EpilogueScene();

	//delete Function
	EpilogueScene(const EpilogueScene& _Other) = delete;
	EpilogueScene(EpilogueScene&& _Other) noexcept = delete;
	EpilogueScene& operator=(const EpilogueScene& _Other) = delete;
	EpilogueScene& operator=(EpilogueScene&& _Other) noexcept = delete;

protected:


private:
	void Start() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	int ScenePage_;
	GameEngineRenderer* SceneRenderer_;
};

