#include "raylib.h"
#include "raymath.h"
#include "stdio.h"
#include "startup.h"



Vector2 InputDIR() {
    int x = 0;
    int y = 0;
    

    if(IsKeyDown(KEY_D) == true)
    {
        x = 1;
    }
    if(IsKeyDown(KEY_A) == true)
    {
        x = -1;
    }
    if(IsKeyDown(KEY_W) == true)
    {
        y = -1;
    }
    if(IsKeyDown(KEY_S) == true)
    {
        y = 1;
    }

    Vector2 PlayerDIR = (Vector2){x , y};
    //SPlayerDIR = Vector2Normalize(PlayerDIR);
    return Vector2Normalize(PlayerDIR);
}

int main()
{


    //InitWindow(GetScreenWidth(), GetScreenHeight(), "window"); // fullscreen w/border
    InitWindow(720, 380, "Raylib - Cozy"); //test window size, not nessasary in full build as we will use fullscreen.
    SetTargetFPS(60);
    SetExitKey(KEY_NULL); //disables ESC from closing window.

    
    Texture2D PlayerBase = LoadTexture("../resources/Body/char1.png");

    PlayerBase.width *= 4; PlayerBase.height *= 4; //upscales texture by 4

    Rectangle frameRec = { 0.0f, 0.0f, (float)PlayerBase.width/8, (float)PlayerBase.height/49}; // 4 is just how long the image is, this should change as i replace the test files
    Vector2 PlayerPOS = {GetRenderWidth()/2, GetRenderHeight()/2};

    //SetWindowState(FLAG_WINDOW_RESIZABLE);

    int currentFrame = 0;           // current sprite frame

    int framesCounter = 0;          // frames till next sprite change
    int framesSpeed =6;            // Number of spritesheet frames shown by second

    float speed = 2; //Char speed movement


    //raylibcredit() dont know how tf im gonna do credits...

    while (!WindowShouldClose()) 
    {
        // Update
        //----------------------------------------------------------------------------------


        framesCounter++;
        if (framesCounter >= (60/framesSpeed)) // updates movement anim
        {

            if (InputDIR().y != 0 || InputDIR().x != 0)
            {
                framesCounter = 0;
                currentFrame++;
            } 
            if (InputDIR().y == 0 && InputDIR().x == 0)
            {
                currentFrame = 0;
            }


            if (currentFrame >= 8) currentFrame = 0; // NEEDS TO HAVE SAME WIDTH AS TEXTURE FRAMES>

            frameRec.x = (float)currentFrame*(float)PlayerBase.width/8; // 8 is number of xframes in animation spritesheet

                    //animation movement setup has to be an if cause apparently switch statement are little bitches that must be set at compile not runtime.
                // switch (true) {
                if(InputDIR().y > 0) //sets movement anim based on input dir
                {
                    frameRec.y = (float)(PlayerBase.height/49)*0;
                } else if (InputDIR().y < 0)
                {
                    frameRec.y = (float)(PlayerBase.height/49)*1;
                } else if (InputDIR().x > 0)
                {
                    frameRec.y = (float)(PlayerBase.height/49)*2;
                } else if (InputDIR().x < 0)
                {
                    frameRec.y = (float)(PlayerBase.height/49)*3;
                } 
        }




        //printf("Drawing\n");
        BeginDrawing();
        
        
        ClearBackground(RAYWHITE);
        //raylibcredit(RaylibLogo);

        PlayerPOS = (Vector2){InputDIR(PlayerPOS).x*speed+PlayerPOS.x, InputDIR(PlayerPOS).y*speed+PlayerPOS.y};


        DrawTextureRec(PlayerBase, frameRec, PlayerPOS, RAYWHITE);


        EndDrawing();
    }

    //TODO unload every resource
    
    UnloadTexture(PlayerBase); 
    CloseWindow();


    printf("closing\n");
    return 0;
}

