#include "include/raylib.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//colors
#define LIGHTBLUE (Color){135, 206, 235, 255}

//global variables & initializations
int gameArray[20][10] = {0}; //represents the game board - 10x20
enum tetriminos{L, L2, Z, Z2, I, O, T}; //for random tetrimino generator (0-6)
time_t t;

typedef struct {
    int id; //unique id will pair it to a tetromino
    Color color; //color
} block;

// for (int i=0; i<20; i++) {
//     for(int j=0; j<10; j++) {
//         gameArray[i][j] = block(-1, WHITE);
//     }
// }

//game helper functions

int calculatePixel(int arrayIndex) //converts from gameArray index to pixel for rendering
{
    return arrayIndex * 50;
}

int newTetrimino()
{
    //pick a random tetrimino and return it based on the enum
    int newRandom = rand() % 7; //generates a random number btw 0 and 6
    return newRandom;
}

int rowFull(int row) //checks if a given row is full; returns 0 if full, 1 if not full.
{
    for(int i=0; i<10; i++){
        if(gameArray[row][i] != 1) {
            return 1; //not full.
        }
    }
    return 0; //row is full.
}

void deleteRow(int row) //slides gameboard above cleared row down to fill it
{
    for(int i=0; i<10; i++)
    {
        gameArray[row][i] = 0; //clear the desired row
    }

    for(int i=row; i>0; i--)
    {
        for(int j=0; j<10; j++)
        {
            gameArray[i][j] = gameArray[i-1][j]; //shift remaining blocks down
        }
    }
}


//main function
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

    InitWindow(900, 1000, "New window");
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
        int position = 5;

        posY += 5;
        if(posY > 950) {
            posY = 950;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
                DrawRectangle(0, 0, 500, 1000, BLUE);
                DrawRectangle(position*50, posY, 50, 50, LIGHTBLUE);
                DrawRectangle((position+1)*50, posY, 50, 50, LIGHTBLUE);
                DrawRectangle((position+2)*50, posY, 50, 50, LIGHTBLUE);
                DrawRectangle((position+2)*50, posY-50, 50, 50, LIGHTBLUE);
            
            for(int i=0; i<20; i++)
            {
                for(int j=0; j<10; j++)
                {
                    DrawRectangle(calculatePixel(i), calculatePixel(j), 50, 50, gameArray[i][j].color);
                }
            }
            
            
        EndDrawing();

    }
    

    CloseWindow();



    return 0;

}

// compile command:
// gcc main.c -o game.exe -Wall -lraylib -lGL -lm -lpthread -ldl -lrt -lX11