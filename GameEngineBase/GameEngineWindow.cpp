#include "GameEngineWindow.h"
#include "GameEngineInput.h"

// HWND hWnd 어떤 윈도우에 무슨일이 생겼는지 그 윈도우의 핸들
// UINT message 그 메시지의 종류가 뭔지
// WPARAM wParam
// LPARAM lParam



LRESULT CALLBACK GameEngineWindow::MessageProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		// 윈도우를 종료할 때 하려는 일
		GameEngineWindow::GetInst().Off();
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_CLOSE:
	{
		GameEngineWindow::GetInst().Off();
		break;
	}
	case WM_MOUSEWHEEL:
	{
		GameEngineInput::GetInst()->WheelValue = (SHORT)HIWORD(wParam);
		break;
	}
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

GameEngineWindow* GameEngineWindow::Inst_ = new GameEngineWindow();
GameEngineWindow::GameEngineWindow()
	: hInst_(nullptr)
	, hWnd_(nullptr)
	, WindowOn_(true)
	, HDC_(nullptr)
{
}

GameEngineWindow::~GameEngineWindow()
{
	// 내가 만들어준게 아니라면 다 지워줘야 한다.
	if (nullptr != HDC_)
	{
		ReleaseDC(hWnd_, HDC_);
		HDC_ = nullptr;
	}
	
	if (nullptr != hWnd_)
	{
		DestroyWindow(hWnd_);
		hWnd_ = nullptr;
	}
}

void GameEngineWindow::Off()
{
	WindowOn_ = false;
}

void GameEngineWindow::RegClass(HINSTANCE _hInst)
{
	// 윈도우 클래스 등록
	WNDCLASSEXA wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = MessageProcess;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = _hInst;
	wcex.hIcon = nullptr;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = "GameEngineWindowClass";
	wcex.hIconSm = nullptr;
	RegisterClassExA(&wcex);
}


void GameEngineWindow::CreateGameWindow(HINSTANCE _hInst, const std::string& _Title)
{
	if (nullptr != hInst_)
	{
		MsgBoxAssert("윈도우를 2번 띄우려고 했습니다");
		return;
	}

	Title_ = _Title;
	hInst_ = _hInst;
	RegClass(_hInst);

	hWnd_ = CreateWindowExA(0L, "GameEngineWindowClass", Title_.c_str(), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _hInst, nullptr);

	// 화면에 무언가를 그리기 위한 핸들
	HDC_ = GetDC(hWnd_);

	if (!hWnd_)
	{
		return;
	}
}

void GameEngineWindow::ShowGameWindow()
{
	if (nullptr == hWnd_)
	{
		MsgBoxAssert("메인 윈도우가 만들어지지 않았습니다 화면에 출력할수 없습니다.");
		return;
	}

	// 이게 호출되기 전까지는 그릴 수 없음
	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_);
}

void GameEngineWindow::MessageLoop(void(*_InitFunction)(), void(*_LoopFunction)())
{
	// 루프를 돌기전에
	// 뭔가 준비할게 있다면 준비함수를 실행한다.


	if (nullptr != _InitFunction)
	{
		_InitFunction();
	}

	MSG msg;

	// 윈도우 내부에서는 보이지 않지만
	// std::list<MSG> MessageQueue;
	// 메세지를 처리했다면 MessageQueue.clear();

	while (WindowOn_)
	{
		
		if (0 != PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// 윈도우가 일하지 않을 때 내 게임에 필요한 것들을 돌린다.
		if (nullptr == _LoopFunction)
		{
			continue;
		}

		_LoopFunction();
	}
}

void GameEngineWindow::SetWindowScaleAndPosition(float4 _Pos, float4 _Scale)
{
	
	
	RECT Rc = { 0 , 0 , _Scale.ix(), _Scale.iy() };

	AdjustWindowRect(&Rc, WS_OVERLAPPEDWINDOW, FALSE);

	Scale_ = _Scale;

	SetWindowPos(hWnd_, nullptr, _Pos.ix(), _Pos.iy(), Rc.right - Rc.left, Rc.bottom - Rc.top, SWP_NOZORDER);
}