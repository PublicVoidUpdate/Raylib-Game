#include <raylib-cpp.hpp>
#include "InputHandler.h"
#include "PlayerScene.h"
#include <stddef.h>
#include <stdlib.h>


const int screenWidth = 720;
const int screenHeight = 380;

void showErrorAndExit(const char *errMsg) {
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText(errMsg, 20, 20, 20, RED);
        EndDrawing();
    }
    
    exit(EXIT_FAILURE);
}

int main() 
{
    int retVal = EXIT_SUCCESS;
    
    // Initialization


    raylib::Window window(screenWidth, screenHeight, "Cozy - cpp");
    
    
    try {
        InputHandler inputHandler;
        // const char raylib[] = "Made using Raylib";
        // Texture2D RaylibLogo = LoadTexture("./Resources/Sprites/raylib_256x256.png");

        std::shared_ptr<Scene> currScene = std::make_shared<PlayerScene>();
        currScene->loadResources();
        currScene->start();


        SetTargetFPS(60);

        // Main game loop
        while (!window.ShouldClose()) // Detect window close button or ESC key
        {

                        inputHandler.handleInput(*currScene);
            auto nextScene = currScene->update();
            if(nextScene) {
                nextScene->loadResources();
                nextScene->start();
                currScene = nextScene;
            }

            // Update

            // TODO: Update your variables here

            // Draw
            BeginDrawing();
            
            currScene->draw();
            // ClearBackground(BLACK);
            // DrawTexture(RaylibLogo, GetRenderWidth()/2 - RaylibLogo.width/2, GetRenderHeight()/2 - RaylibLogo.height/2, RAYWHITE);
            // DrawText(raylib, (GetRenderWidth()/2) - (MeasureText(raylib, 10)/2), (GetRenderHeight()/2 + RaylibLogo.height/2), 10, RAYWHITE);
 
            EndDrawing();
            
        } 
        //UnloadTexture(RaylibLogo); 
    } catch(std::runtime_error &e) {
        showErrorAndExit(e.what());
        retVal = EXIT_FAILURE; 
    }
    

    return retVal;

}