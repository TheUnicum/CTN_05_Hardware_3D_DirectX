#pragma once
#include "Window.h"
#include "ChiliTimer.h"
#include "ImguiManager.h"
#include "Camera.h"
#include "PointLight.h"
#include "TestPlane.h"
#include "Mesh.h"
#include <set>

class App
{
public:
	App(const std::string& commandLine = "");
	// master frame / message loop
	int Go();
	~App();
private:
	void DoFrame();
	void ShowImguiDemoWindow();
private:
	std::string commandLine;
	bool showDemoWindow = false;
	ImguiManager imgui;
	Window wnd;
	ChiliTimer timer;
	float speed_factor = 1.0f;
	Camera cam;
	PointLight light;
	Model gobber{ wnd.Gfx(),"src\\models\\gobber\\GoblinX.obj",6.0f };
	Model wall{ wnd.Gfx(),"src\\models\\brick_wall\\brick_wall.obj",6.0f };
	TestPlane tp{ wnd.Gfx(),6.0 };
	Model nano{ wnd.Gfx(),"src\\models\\nano_textured\\nanosuit.obj",2.0f };
};
