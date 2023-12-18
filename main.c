#include "include/raylib.h"
#include <stdio.h>

int main()
{
    //initialize textures and main stage

    int posY = -150;

    Texture2D L;
    Texture2D L2;
    Texture2D Z;
    Texture2D Z2;
    Texture2D I;
    Texture2D O;
    Texture2D T;

    InitWindow(500, 1000, "New window");
    L = LoadTexture("Assets/L.png");
    L2 = LoadTexture("Assets/L2.png");
    Z = LoadTexture("Assets/Z.png");
    Z2 = LoadTexture("Assets/Z.png");
    I = LoadTexture("Assets/I.png");
    O = LoadTexture("Assets/O.png");
    T = LoadTexture("Assets/T.png");

    SetTargetFPS(60);

    //window loop
    while(!WindowShouldClose())
    {
        posY += 5;
        if(posY > 850) {
            posY = 850;
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(L2, 10, 10, WHITE);
            DrawTexture(L, 110, posY, WHITE);
            DrawTexture(L, 260, 10, WHITE);
        EndDrawing();

    }
    

    CloseWindow();



    return 0;

}

// compile command:
// gcc main.c -o game.exe -Wall -lraylib -lGL -lm -lpthread -ldl -lrt -lX11