#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineRenderer;
class SceneChanger : public GameEngineActor
{
public:
	//construcuter destructer
	SceneChanger();
	~SceneChanger();

	//delete Function
	SceneChanger(const SceneChanger& _Other) = delete;
	SceneChanger(SceneChanger&& _Other) noexcept = delete;
	SceneChanger& operator=(const SceneChanger& _Other) = delete;
	SceneChanger& operator=(SceneChanger&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* MyRenderer_;
	bool PlayOpenSound_;
	bool PlayCloseSound_;

	void Start() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
};

