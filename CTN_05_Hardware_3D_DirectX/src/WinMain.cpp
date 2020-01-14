/******************************************************************************************
*	Chili Direct3D Engine																  *
*	Copyright 2018 PlanetChili <http://www.planetchili.net>								  *
*																						  *
*	This file is part of Chili Direct3D Engine.											  *
*																						  *
*	Chili Direct3D Engine is free software: you can redistribute it and/or modify		  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Chili Direct3D Engine is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Chili Direct3D Engine.  If not, see <http://www.gnu.org/licenses/>.    *
******************************************************************************************/
#include "Window.h"


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	Window wnd(800, 300, "Donkey Fart Box");

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		// TranslateMessage will post auxilliary WM_CHAR messages from key msgs
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// check if GetMessage call itself borked
	if (gResult == -1)
	{
		return -1;
	}
	
	// wParam here is the value passed to PostQuitMessage
	return msg.wParam;
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