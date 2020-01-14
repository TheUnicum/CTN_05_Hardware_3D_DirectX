#include <Windows.h>

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
	wc.lpfnWndProc = DefWindowProc;
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
	while (true);
	return 0;
}

/*
WinMain function
https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-winmain
WNDCLASSEX
https://docs.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-wndclassexa
CreateWindowEx
"https://docs.microsoft.com/en-us/previous-versions/ms960010(v%3Dmsdn.10)"
*/