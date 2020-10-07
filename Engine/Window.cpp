#include "Window.h"

Window::Window()
{
    _window = SDL_CreateWindow("SDL2 Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        680, 480,
        0);

    if (!_window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    _windowSurface = SDL_GetWindowSurface(_window);

    if (!_windowSurface)
    {
        std::cout << "Failed to get window's surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
    
}

Window::~Window()
{
    SDL_FreeSurface(_windowSurface);
    SDL_DestroyWindow(_window);
}

void Window::Draw()
{
    SDL_UpdateWindowSurface(_window);
}

void Window::Loop()
{
    bool keep_window_open = true;
    while (keep_window_open)
    {
        while (SDL_PollEvent(&_windowEvent) > 0)
        {
            switch (_windowEvent.type)
            {
            case SDL_QUIT:
                keep_window_open = false;
                break;
            }
        }

        Update(1.0 / 60.0);
        Draw();
    }
}


void Window::Update(double deltaTime)
{

}
