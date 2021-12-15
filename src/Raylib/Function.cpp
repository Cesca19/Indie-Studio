/*
** EPITECH PROJECT, 2021
** B-YEP-400-COT-4-1-indiestudio-femi.facia
** File description:
** Function
*/

#include "myRaylib.hpp"

namespace Raylib {
    /**
     * @brief CheckCollisionRayBox
     * 
     * @param ray 
     * @param box 
     * @return true 
     * @return false 
     */
    bool checkCollisionRayBox(Ray ray, BoundingBox box)
    {
        return CheckCollisionRayBox(ray, box);
    }
    /**
     * @brief Return a ray trace for mouse position
     * 
     * @param mousePosition 
     * @param camera 
     * @return Ray 
     */
    Ray getMouseRay(Vector2 mousePosition, Camera camera)
    {
        return GetMouseRay(mousePosition, camera);
    }

    /**
     * @brief Set camera mode (multiple camera modes available)
     * 
     * @param camera 
     * @param mode 
     */

    void setCameraMode(Camera camera, int mode)
    {
        SetCameraMode(camera, mode);
    }
    
    /**
     * @brief Get the Time object
     * 
     * @return double 
     */

    double getTime(void)
    {
        return (GetTime());
    }

    /**
     * @brief Update camera position for selected mode
     * 
     * @param camera 
     */
    void updateCamera(Camera *camera)
    {
        UpdateCamera(camera);
    }
    
    /**
     * @brief  Ends 3D mode and returns to default 2D orthographic mode
     * 
     */
    void endMode3D(void)
    {
        EndMode3D();
    }

    void drawText(std::string str, int x, int y, int size, Color color)
    {
        DrawText(str.c_str(), x, y, size, color);
    }

    /**
     * @brief Initializes 3D mode with custom camera (3D)
     * 
     * @param camera 
     */
    void beginMode3D(Camera3D camera)
    {
        BeginMode3D(camera); 
    }

    /**
     * @brief Set target FPS (maximum)
     * 
     * @param target 
     */
    void setTargetFPS(int target)
    {
        SetTargetFPS(target);
    }

    /**
     * @brief Returns mouse position XY
     * 
     * @return Vector2 
     */
    Vector2 getMousePosition(void) {
        return GetMousePosition();
    }
    
    /**
     * @brief Detect if a mouse button is being pressed
     * 
     * @param button 
     * @return true 
     * @return false 
     */
    bool isMouseButtonDown(int button)
    {
        return IsMouseButtonDown(button);
    }
    
    /**
     * @brief Detect if a mouse button has been pressed once
     * 
     * @param button 
     * @return true 
     * @return false 
     */
    bool isMouseButtonPressed(int button)
    {
        return IsMouseButtonPressed(button);
    }
    
    /**
     * @brief Get key pressed (keycode), call it multiple times for keys queued
     * 
     * @return int 
     */
    int getKeyPressed(void)
    {
        return GetKeyPressed();
    }
    
    /**
     * @brief Detect if a key is being pressed
     * 
     * @param key 
     * @return true 
     * @return false 
     */
    bool isKeyDown(int key)
    {
        return IsKeyDown(key);
    }
    
    /**
     * @brief Detect if a key has been pressed once
     * 
     * @param key 
     * @return true 
     * @return false 
     */
    bool isKeyPressed(int key)
    {
        return IsKeyPressed(key);
    }
    
    /**
     * @brief 
     * Initialize audio device and context
     */
    void initAudioDevice(void)
    {
        InitAudioDevice();
    }
    
    /**
     * @brief Close the audio device and context
     * 
     */
    void closeAudioDevice(void)
    {
        CloseAudioDevice();
    }
    
    /**
     * @brief Setup canvas (framebuffer) to start drawing
     * 
     */
    void beginDrawing()
    {
        BeginDrawing();
    }
    
    /**
     * @brief End canvas drawing and swap buffers (double buffering)
     * 
     */
    void endDrawing()
    {
        EndDrawing();
    }

    bool winShouldClose()
    {
        return WindowShouldClose();
    }

    Color getColor(std::string str)
    {
        if (str == "BEIGE")
            return BEIGE;
        if (str == "BLUE")
            return BLUE;
        if (str == "PINK")
            return (PINK);
        if (str == "YELLOW")
            return (YELLOW);
        if (str == "GREEN")
            return GREEN;
        if (str == "RED")
            return (RED);
        if (str == "ORANGE")
            return (ORANGE);
        if (str == "WHITE")
            return (WHITE);
        if (str == "BROWN")
            return (BROWN);
        if (str == "VIOLET")
            return (VIOLET);
        if (str == "LIGHTGRAY")
            return LIGHTGRAY;
        if (str == "GRAY")
            return (GRAY);
        if (str == "DARKGRAY")
            return DARKGRAY;
        if (str == "GOLD")
            return (GOLD);
        if (str == "MAROON")
            return (MAROON);
        if (str == "LIME")
            return (LIME);
        if (str == "PURPLE")
            return (PURPLE);
        if (str == "DARKGREEN")
            return (DARKGREEN);
        if (str == "DARKBLUE")
            return (DARKBLUE);
        if (str == "SKYBLUE")
            return (SKYBLUE);
        if (str == "MAGENTA")
            return (MAGENTA);
        if (str == "DARKPURPLE")
            return (DARKPURPLE);
        if (str == "DARKBROWN")
            return (DARKBROWN);
        if (str == "BLANK")
            return (BLANK);
        if (str == "RAYWHITE")
            return (RAYWHITE);
        return (BLACK);
    }
}