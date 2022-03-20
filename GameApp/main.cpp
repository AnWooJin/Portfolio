#include <Windows.h>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineContents/HellTakerGame.h>

int __stdcall WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ char* IpCmdLine,
	_In_ int       nCmdShow)
{
	// ���� ���� ������ Ŭ���� ���� ���ø����� �־��ָ�
	// �����츦 ����� �ش�.
	GameEngine::Start<HellTakerGame>();
}