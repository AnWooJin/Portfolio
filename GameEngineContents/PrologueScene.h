#pragma once
class PrologueScene
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

};

