#include <Windows.h>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineContents/HellTakerGame.h>


HellTakerGame MyGame;

void GameInit()
{
	// 텍스쳐를 로딩하고 준비하는 곳
	// 오브젝트를 미리 만들어두는 곳
	
	// 루프를 돌리기 전에 준비해야하는 것들...
	MyGame.GameInit();

}

void GameLoop()
{
	// 이 안에 만들 프로그램의 로직을 넣는다.

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