#include "include/raylib.h"

int main()
{
    InitWindow(800, 450, "New window");

    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Test Window", 190, 200, 20, LIGHTGRAY);
        EndDrawing();

    }
    

    CloseWindow();



    return 0;

}

// compile command:
// gcc main.c -o game.exe -Wall -lraylib -lGL -lm -lpthread -ldl -lrt -lX11