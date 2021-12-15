/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** setMapName
*/

#include "Bomberman.hpp"
#include <vector>
#include <iostream>
#include <fstream>

void store_data(char *name, std::vector<std::string> data)
{
    std::string tmp (name);
    std::string path("../src/Bomberman/Map/");
    path.append(tmp);
    path.append(".txt");
    std::cout << path << std::endl;
    std::ofstream myfile(path);
    if(!myfile.is_open()) {
        std::cout<<"Error in creating file!!!";
        return;
    }
    for (int i = 0; i < data.size(); i++) {
        myfile << data[i] << std::endl;
        // std::cout << data[i] + "\n";
    }
    myfile.close();
}

char *get_name(char *name, int &letterCount, bool &get, std::vector<std::string> map)
{
    int key = GetCharPressed();

    while (key > 0)
    {
        if ((key >= 32) && (key <= 125) && (letterCount < 10))
        {
            name[letterCount] = (char)key;
            name[letterCount + 1] = '\0';
            letterCount++;
        }

        key = GetCharPressed();
    }

    if (Raylib::isKeyDown(KEY_BACKSPACE))
    {
        letterCount--;
        if (letterCount < 0)
            letterCount = 0;
        name[letterCount] = '\0';
    }
    if (Raylib::isKeyDown(KEY_ENTER) && letterCount != 0)
    {
        store_data(name, map);
        get = false;
    }
    return name;
}

void setMapName(Raylib::Window *win, Engine::Scene *scene, std::vector<std::string> map)
{
    int letterCount = 0;
    bool getting = true;
    char g_name[10 + 1] = "\0";
    Raylib::Text name;
    Raylib::RayRectangle text_box(225, 50);
    text_box.setPosition(600 / 2 - 100, 180);
    name.setPosition({((float)600 / 2 - 100) + 5, 188});
    name.setColor(WHITE);
    name.setFontSize(60);
    name.setSpacing(10);
    name.setFont("");

    while (scene->shouldContinue() && getting) {
        if (getting)
            get_name(g_name, letterCount, getting, map);
        name.setText(g_name);

        Raylib::beginDrawing();
        scene->Display(win);
        if (getting) {
            Raylib::drawText("TYPE THE NAME OF YOUR MAP!", 40, 40, 70, GRAY);
            //text_box.draw(BLUE);
            name.draw();
            Raylib::drawText(TextFormat("INPUT CHARS: %i/%i", letterCount, 10), 315, 350, 40, WHITE);
        }
        Raylib::endDrawing();
    }
}