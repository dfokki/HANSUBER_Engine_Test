#pragma once
#include <SDL_surface.h>
#include <SDL_video.h>
#include <SDL_events.h>
#include <iostream>

class Window
{
private:
	
	SDL_Window * _window;
	SDL_Surface* _windowSurface;
	SDL_Event    _windowEvent;
public:
	SDL_Surface* GetWindowSurface() {return _windowSurface;};
	Window();
	~Window();
	void Draw();
	void Update( double deltaTime);
	void Loop();


};

