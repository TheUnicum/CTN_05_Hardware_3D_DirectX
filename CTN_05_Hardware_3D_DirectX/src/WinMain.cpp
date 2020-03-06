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
#include "App.h"


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	try
	{
		return App{ lpCmdLine }.Go();
	}
	catch (const ChiliException & e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception & e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
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
PeekMessageA function
https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-peekmessagea
****COM****
IUnknown interface
https://docs.microsoft.com/en-us/windows/win32/api/unknwn/nn-unknwn-iunknown
IUnknown::QueryInterface method
https://docs.microsoft.com/en-us/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface%28refiid_void%29
Generating Interface UUIDs
https://docs.microsoft.com/en-us/windows/win32/rpc/generating-interface-uuids
CoCreateInstance function
https://docs.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance
T12
IDXGIFactory2 interface
https://docs.microsoft.com/en-us/windows/win32/api/dxgi1_2/nn-dxgi1_2-idxgifactory2
D3D11CreateDeviceAndSwapChain function
https://docs.microsoft.com/en-us/windows/win32/api/d3d11/nf-d3d11-d3d11createdeviceandswapchain
DXGI Overview
https://docs.microsoft.com/en-us/windows/win32/direct3ddxgi/d3d10-graphics-programming-guide-dxgi
*****
Pipelines for Direct3D Version 11
https://docs.microsoft.com/en-us/windows-hardware/drivers/display/pipelines-for-direct3d-version-11
Primitive Topologies
https://docs.microsoft.com/en-us/windows/win32/direct3d11/d3d10-graphics-programming-guide-primitive-topologies

[T32] - Specular map: What about the specular reflection's highlight' size?
https://gamedev.stackexchange.com/questions/74879/specular-map-what-about-the-specular-reflections-highlight-size
*/