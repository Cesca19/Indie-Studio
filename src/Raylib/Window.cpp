/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Window
*/

#include "../../include/Raylib/Window.hpp"

namespace Raylib {
    void Window::setFullscreen()
    {
        toggleFullscreen();
    }

    bool Window::shouldClose(void)
    {
        return (WindowShouldClose());
    }

    void Window::setBackground(std::string path)
    {
        if (path != _backgroundPath) {
            _backgroundText.loadTexture(path.c_str());
            _backgroundPath = path;
        }
        _backgroundText.draw(0, 0, WHITE);
    }

    void Window::setBackground(Color color)
    {
        ClearBackground(color);
    }

    void Window::setWindowPosition(int x, int y)
    {
        SetWindowPosition(x,y);
    }

    void Window::toggleFullscreen()
    {
        if (!_is_screen_init) {
            SetWindowState(FLAG_FULLSCREEN_MODE);
            _is_screen_init = 1;
        }
        else
            ToggleFullscreen();
    }

    bool Window::isWindowFullscreen()
    {
        return IsWindowFullscreen();
    }

    bool Window::isWindowReady()
    {
        return IsWindowReady();
    }

    void Window::Close()
    {
        if (_backgroundPath != "")
            _backgroundText.unloadTexture();
        CloseWindow();
    }

    void Window::Init()
    {
        InitWindow(_width, _height, _name.c_str()); 
        _is_screen_init = 0;
        if (IsWindowReady() == false)
            exit(0);
    }

    Window::Window(int width, int height, std::string name) : _width(width), _height(height), _name(name), _backgroundText(1)
    {
        _backgroundPath = "";
        Init();
    }

    Window::~Window()
    {
        Close();
    }
};