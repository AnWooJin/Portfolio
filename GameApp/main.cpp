#include <Windows.h>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineContents/HellTakerGame.h>


HellTakerGame MyGame;

void GameInit()
{
	// �ؽ��ĸ� �ε��ϰ� �غ��ϴ� ��
	// ������Ʈ�� �̸� �����δ� ��
	
	// ������ ������ ���� �غ��ؾ��ϴ� �͵�...
	MyGame.GameInit();

}

void GameLoop()
{
	// �� �ȿ� ���� ���α׷��� ������ �ִ´�.

	MyGame.GameLoop();
}

int __stdcall WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ char* IpCmdLine,
	_In_ int       nCmdShow)
{


	GameEngineDebug::LeakCheckOn();

	GameEngineWindow::GetInst().CreateGameWindow(hInstance, "GameWindow");
	GameEngineWindow::GetInst().ShowGameWindow();
	GameEngineWindow::GetInst().MessageLoop(GameInit,GameLoop);


	GameEngineWindow::Destory();

	MyGame.GameEnd();
}