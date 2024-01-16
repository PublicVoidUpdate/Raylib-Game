#include "raylib.h"
#include "startup.h"
#include "stdio.h"


    void raylibcredit()
    {
        BeginDrawing();
        Texture2D RaylibLogo = LoadTexture("../resources/raylib_256x256.png");
        const char raylib[] = "Made using Raylib";

        ClearBackground(BLACK);
        DrawTexture(RaylibLogo, GetRenderWidth()/2 - RaylibLogo.width/2, GetRenderHeight()/2 - RaylibLogo.height/2, RAYWHITE);


        DrawText(raylib, (GetRenderWidth()/2) - (MeasureText(raylib, 10)/2), (GetRenderHeight()/2 + RaylibLogo.height/2), 10, RAYWHITE);
        int x = 120;
        if(x <= 0)
        {
            UnloadTexture(RaylibLogo);
            EndDrawing();
            return;
        } else
        {
            x--;
        }

        
    }

