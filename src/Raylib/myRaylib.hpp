/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Raylib
*/

#ifndef MY_RAYLIB_HPP_
#define MY_RAYLIB_HPP_
#include <iostream>
#include "../../cmake/include/raylib.h"

namespace Raylib {
    double getTime(void);
    void drawText(std::string str, int x, int y, int size, Color color);
    void setCameraMode(Camera camera, int mode);
    void updateCamera(Camera *camera);
    void endMode3D(void);
    void beginMode3D(Camera3D camera);
    Color getColor(std::string str);
    void setTargetFPS(int target);
    Vector2 getMousePosition(void);
    Ray getMouseRay(Vector2 mousePosition, Camera camera);
    bool checkCollisionRayBox(Ray ray, BoundingBox box);
    void beginDrawing();
    void endDrawing();
    void closeAudioDevice(void);
    void initAudioDevice(void);
    bool isKeyPressed(int key);
    bool isKeyDown(int key);
    int getKeyPressed(void);
    bool isMouseButtonPressed(int button);
    bool isMouseButtonDown(int button);
    bool winShouldClose(void);
};

#endif /* !MY_RAYLIB_HPP_ */
