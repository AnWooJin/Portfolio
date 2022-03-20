#include <Windows.h>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineContents/HellTakerGame.h>

int __stdcall WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ char* IpCmdLine,
	_In_ int       nCmdShow)
{
	// 내가 만들 게임의 클래스 명을 템플릿으로 넣어주면
	// 윈도우를 만들어 준다.
	GameEngine::Start<HellTakerGame>();
}