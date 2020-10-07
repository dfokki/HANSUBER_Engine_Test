#include "Application.h"
#include <iostream>
#include "Image.h"
Application::Application()
{
    window = new Window();
    auto image = new Image("lisko.png", window);
    int i = 0;
    while (i < sizeof(int))
    {
        i++;
        std::cout << "DANCE MONKEY DANCE!" << std::endl;
    }

}

Application::~Application()
{
    window->~Window();
}

void Application::Draw()
{
    window->Draw();
    window->Update(0.0);
}

void Application::Update(double deltaTime)
{

}

void Application::Loop()
{
    window->Loop();
}