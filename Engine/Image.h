#pragma once
#include <SDL_surface.h>
#include <vector>
#include"VectorClass/vectorclass.h"
#include "Window.h"

class Image
{
private:
	SDL_Rect _rect;

public:
	Image(char const* filepath, Window *window);
	~Image();

	int PosX;
	int PosY;
	int Width;
	int Height;

	void SetRect();

	Vec2d CurrentPos;
	Vec2d GetPosition();
	Vec2d SetPosition(int x, int y);
	void SetSize(int w, int h);
};

