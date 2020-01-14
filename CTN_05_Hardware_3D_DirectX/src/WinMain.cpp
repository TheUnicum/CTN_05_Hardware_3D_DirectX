#include <Windows.h>
#include "WindowsMessageMap.h"
#include <sstream>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static WindowsMessageMap mm;
	OutputDebugString(mm(msg, lParam, wParam).c_str());

	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	case WM_KEYDOWN:
		if (wParam == 'D')
		{
			SetWindowText(hWnd, "Respects");
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, "Dangerfield");
		}
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	const auto pClassName = "hw3dbutts"; // -> Set Avanzate/Set Caratteri->Utilizza set di caratteri multibyte
	// register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);
	// create window instance
	HWND hWnd = CreateWindowEx(
		0, pClassName,
		"Happy Hard Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);
	// show the damn window
	ShowWindow(hWnd, SW_SHOW);

	// message pump
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
}

/*
WinMain function
https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-winmain
WNDCLASSEX
https://docs.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-wndclassexa
CreateWindowEx
"https://docs.microsoft.com/en-us/previous-versions/ms960010(v%3Dmsdn.10)"
GetMessage function
https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getmessage
MSG structure
https://docs.microsoft.com/it-it/windows/win32/api/winuser/ns-winuser-msg
DefWindowProcA function
https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-defwindowproca
List Of Windows Messages
https://wiki.winehq.org/List_Of_Windows_Messages
WM_KEYDOWN message
https://docs.microsoft.com/en-us/windows/win32/inputdev/wm-keydown
Virtual-Key Codes
https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
*/