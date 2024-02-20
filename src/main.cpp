#include "raylib.h"
#include "raymath.h"
#include "stdio.h"
#include <filesystem>
#include <iostream>
#include "fstream"
#include <set>

using namespace std;
namespace fs = std::filesystem;


void LoadArray()
{

    for (int i = 0; i < 11; i++) {

          //--- filenames are unique so we can use a set
        string workpath = "./Content/Sprites/Composite/" + std::to_string(i);
        set<fs::path> sorted_by_name;

  for (auto &entry : fs::directory_iterator(workpath))
    sorted_by_name.insert(entry.path());

    

  //--- print the files sorted by filename
    //for (auto &filename : sorted_by_name)
        //cout << filename.c_str() << endl;


    }
    


}

int main()
{
    // printf("\x1B[31mTexting\033[0m\n");

        // -------------------- Run Once Logic ---------

    InitWindow(720, 380, "Skin Editor");
    SetTargetFPS(60);

    //How long the raylib logo should appear for
    int Timer = 180;
    
    //Texture2D RaylibLogo = LoadTexture("./Content/Sprites/RaylibLogo.png");
    //const char raylib[] = "Made using Raylib";





    SetWindowState(FLAG_WINDOW_RESIZABLE);

//----------------Try/Catch for read/write -----------------
    try{
        //const char path[] = "./ReadWritecheck";
        //std::ofstream(path).flush();;
        std::ofstream output("./ReadWritecheck");
        fs::path f{ "./ReadWritecheck" };
        if (!fs::exists(f)) throw runtime_error("");
            }
    catch(const exception& error){
        printf("I can't seem to create anything... Please dont be mad....", "\n");
        printf("\n\x1B[31mERROR!! NO READ/WRITE PERMISSIONS CANNOT SAVE OR LOAD DATA!!\033[0m\n");
    }
//----------------end of Try/Catch for read/write -----------------

        Texture2D PlayerBase = LoadTexture("./Content/Sprites/Composite/0/char1.png");
        Texture2D PlayerBG = LoadTexture("./Content/Sprites/Seasons.png");
        Texture2D Trash = LoadTexture("./Content/Sprites/Trash.png");

    Rectangle playerRec;
    Rectangle BGrec;


                // -------------------- Shady shit that probs wont work ---------
        LoadArray();


    while (!WindowShouldClose()) 
    {

        //printf("Drawing\n");
        BeginDrawing();
        
        
        
        //------------------------- Runs the raylib logo unless the time is up -------------------------
        // if(Timer >= 0)
        // {

        //     RaylibLogo.width = GetRenderHeight()/2;
        //     RaylibLogo.height = GetRenderHeight()/2;

        //     ClearBackground(BLACK);
        //     DrawTexture(RaylibLogo, GetRenderWidth()/2 - RaylibLogo.width/2, GetRenderHeight()/2 - RaylibLogo.height/2, RAYWHITE);
        //     DrawText(raylib, (GetRenderWidth()/2) - (MeasureText(raylib, 10)/2), (GetRenderHeight()/2 + RaylibLogo.height/2), 10, RAYWHITE);
        //     Timer--;
        // } else
        // {
            //main update loop after logo
        // --------------------- Updates every frame after the startup logo --------------------



            //printf("%d", GetRenderWidth());
            char Console[] = "Current Skin Value\n";
           

        //--------------------- Update size based on screen width. ----------------------
        PlayerBase.width = GetRenderWidth()/4*8;
        PlayerBase.height = GetRenderWidth()/4*49;
        PlayerBG.width = GetRenderWidth()/4*6;
        PlayerBG.height = GetRenderWidth()/4*1.5;
        Trash.width = GetRenderWidth()/12;
        Trash.height = GetRenderWidth()/6;
        //DrawTexture(PlayerBG, GetRenderWidth()/2 - PlayerBG.width/2, GetRenderHeight()/2 - PlayerBG.height/2, RAYWHITE);

        //--------------------- Udate Rec from updated texture sizes (will crop the image without) -----------------
        playerRec = { 0.0f, 0.0f, (float)PlayerBase.width/8, (float)PlayerBase.height/49};
        BGrec = { 0.0f, 0.0f, (float)PlayerBG.width/8, (float)PlayerBG.height};
    //------------------- Draw all objects to the screen ---------------
    ClearBackground(RAYWHITE);
        //--------------------- Draw only the part of the texture that fits inside the texture rect. --------------------
        DrawTextureRec(PlayerBG, BGrec, (Vector2){GetRenderWidth()/2-(float)BGrec.width/2, GetRenderHeight()/2-(float)BGrec.height/2}, RAYWHITE);
        DrawTextureRec(PlayerBase, playerRec, (Vector2){GetRenderWidth()/2-(float)playerRec.width/2, GetRenderHeight()/2-(float)playerRec.height/2-(float)BGrec.height/6.5}, RAYWHITE);
        DrawText(Console, (3), (3), 20, BLACK);
        DrawTexture(Trash, GetRenderWidth() - Trash.width*1.5, GetRenderHeight() - Trash.height*1.25, RAYWHITE);
                // (float){GetRenderWidth()/2 - PlayerBase.width/2}, (float){GetRenderHeight()/2 - PlayerBase.height/2}
        // }



        // -------------------- No update logic past this point. -----------------------



        EndDrawing();
    }

    //--------------------- Unload every resource and close --------------------------
    UnloadTexture(PlayerBase); 
    UnloadTexture(PlayerBG);
    UnloadTexture(Trash); 
    std::filesystem::remove("./ReadWritecheck");

    CloseWindow();
    printf("closing\n");
    return 0;
}

