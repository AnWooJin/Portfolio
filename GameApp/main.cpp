#include <Windows.h>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>

void GameLoop()
{
	// �� �ȿ� ���� ���α׷��� ������ �ִ´�.
}

int __stdcall WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ char* IpCmdLine,
	_In_ int       nCmdShow)
{


	GameEngineDebug::LeakCheckOn();

	GameEngineWindow::GetInst().CreateGameWindow(hInstance, "GameWindow");
	GameEngineWindow::GetInst().ShowGameWindow();
	GameEngineWindow::GetInst().MessageLoop(GameLoop);


	GameEngineWindow::Destory();
}