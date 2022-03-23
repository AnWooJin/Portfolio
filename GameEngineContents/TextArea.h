#pragma once
#include <GameEngine/GameEngineActor.h>

class TextArea : public GameEngineActor
{
public:
	//construcuter destructer
	TextArea();
	~TextArea();

	//delete Function
	TextArea(const TextArea& _Other) = delete;
	TextArea(TextArea&& _Other) noexcept = delete;
	TextArea& operator=(const TextArea& _Other) = delete;
	TextArea& operator=(TextArea&& _Other) noexcept = delete;

protected:

private:
	void Start() override {};
	void Render() override {};
};

