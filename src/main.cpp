#include <raylib-cpp.hpp>
#include "errorhandling.hpp"



int main() {


    // -------------------- Run Once Logic ---------
    readcheck(); //should split read and write, crash on read fail, continue on ROMode if write fail
    
    // Initialization
    int screenWidth = 720;
    int screenHeight = 380;

    raylib::Color textColor(BLACK);
    raylib::Window w(screenWidth, screenHeight, "Debug Rewrite");
    
    SetTargetFPS(60);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    
    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key //should def turn off esc but ill do it later
    {
        // ----------------------- Updates every frame ---------------------


        BeginDrawing();
        ClearBackground(RAYWHITE);
        textColor.DrawText("Congrats! You created your first window!", 190, 200, 20);

        // -------------------- No update logic past this point. -----------------------
        EndDrawing();
    }


    //--------------------- Unload every resource and close --------------------------
    CloseWindow();
    printf("closing\n");
    //--------------------- return exit code should be zero unless there is issue ----------------------------
    return 0;
}