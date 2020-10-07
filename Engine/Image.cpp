#include "Image.h"

SDL_Surface* load_surface(char const* path)
{
   auto _imageSurface = SDL_LoadBMP(path);

    if (!_imageSurface)
        return 0;

    return _imageSurface;
}


Image::Image(char const* filepath, Window* window)
{
    auto img = load_surface(filepath);
    this->PosX = 1;
    this->PosY = 0;
    this->Width = 25;
    this->Height = 43;
    SetRect();
    SDL_BlitSurface(img, NULL, window->GetWindowSurface(), &_rect);
}

Image::~Image()
{
}

void Image::SetRect()
{
    this->_rect.x = PosX;
    this->_rect.y = PosY;
    this->_rect.w = Width;
    this->_rect.h = Height;
}


Vec2d Image::GetPosition()
{
    return Vec2d(this->PosX,this->PosY);
}

Vec2d Image::SetPosition(int x, int y)
{
    CurrentPos = Vec2d(x, y);
    SetRect();
    return CurrentPos;
}

void Image::SetSize(int w, int h)
{
    _rect.w = w;
    _rect.h = h;
}
