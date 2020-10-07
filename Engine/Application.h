#pragma once
#include <SDL_video.h>
#include <SDL_events.h>
#include "Window.h"
class Application : Window
{

private:
	Window *window;
public:
	Application();
	~Application();
	void Draw();
	void Update(double deltaTime);
	void Loop();
};

