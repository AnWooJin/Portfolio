#pragma once
#include <GameEngine/GameEngineActor.h>

class GameEngineRenderer;
class DevilSD : public GameEngineActor
{
public:
	//construcuter destructer
	DevilSD();
	DevilSD(int _Level);
	~DevilSD();

	//delete Function
	DevilSD(const DevilSD& _Other) = delete;
	DevilSD(DevilSD&& _Other) noexcept = delete;
	DevilSD& operator=(const DevilSD& _Other) = delete;
	DevilSD& operator=(DevilSD&& _Other) noexcept = delete;

	void ImageSetting(int _ChapterLevel);
protected:

private:
	void Start() override;
	void Update() override;
	void Render() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	void CreateClearEffect();
	void ChapterSucess();

	void Chapter3Sucess();
	void elseChapterSucess();

	GameEngineRenderer* MyRenderer_;
	GameEngineRenderer* MyRenderer1_;
	GameEngineRenderer* MyRenderer2_;

	GameEngineRenderer* FilterRenderer_;
	GameEngineRenderer* FilterRenderer1_;
	GameEngineRenderer* FilterRenderer2_;

	int Chapter_;
	bool IsEffect_;
	bool SoundPlay_;
	float Time_;
	
};

