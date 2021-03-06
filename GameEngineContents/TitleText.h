#pragma once
#include <GameEngine/GameEngineActor.h>

enum class TitleTextState
{
	Text,
	Prologue,
	SceneChagnger,
	Max,
};

class GameEngineRenderer;
class TitleText : public GameEngineActor
{
public:
	//construcuter destructer
	TitleText();
	~TitleText();

	//delete Function
	TitleText(const TitleText& _Other) = delete;
	TitleText(TitleText&& _Other) noexcept = delete;
	TitleText& operator=(const TitleText& _Other) = delete;
	TitleText& operator=(TitleText&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* MyRenderer_;
	TitleTextState CurState_;

	void Start() override;
	void Update() override;
	void Render() override {};

	void LevelChangeStart(GameEngineLevel* _PrevLevel);
	void ChangeState(TitleTextState _State);
	void StateUpdate();

private:
	void TextStart();
	void PrologueStart();
	void SceneChangerStart();

	void TextUpdate();
	void PrologueUpdate();
	void SceneChangerUpdate();

	bool PlayOpenSound_;
	bool PlayCloseSound_;
};

