#include "include/raylib.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//colors
#define LIGHTBLUE (Color){135, 206, 235, 255}
#define BACKGROUND (Color){103, 128, 159, 255}

//global variables & initializations
typedef struct {
    int id; //unique id will pair it to a tetromino - -1 means empty
    Color color; //color
} block;

//enum tetriminos{L, L2, Z, Z2, I, O, T}; //for random tetrimino generator (0-6)
//time_t t;

//block gameArray[20][10] = {0}; //represents the game board - 10x20
    //figure out how to properly allocate memory for this situation


//game helper functions
void background()
{
    DrawRectangle(0, 0, 500, 1000, BACKGROUND);
}

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

int rowFull(block row[10]) //checks if a given row is full - takes in a pointer to a row of 10 cols
{
    for(int i=0; i<10; i++){
        if(row[i].id != -1) {
            return 0; //false.
        }
    }
    return 1; //row is full (true).
}

void deleteRow(block row[10]) //slides gameboard above cleared row down to fill it - takes in a pointer to a row of 10 cols
{
    for(int i=0; i<10; i++)
    {
        row[i].id = -1; //clear the desired row
        row[i].color = BACKGROUND;
    }

    // for(int i=row; i>0; i--)
    // {
    //     for(int j=0; j<10; j++)
    //     {
    //         gameArray[i][j] = gameArray[i-1][j]; //shift remaining blocks down
    //     }
    // }
}


//main function
int main()
{

    //create and allocate memory for the game board
    block** gameArray;
    gameArray = (block**)malloc(20 * sizeof(block*));
    if(gameArray == NULL) 
    {
        fprintf(stderr, "Could not allocate memory for the gameArray.\n");
    }   
    for(int i=0; i<20; i++)
    {
        gameArray[i] = (block*)malloc(10*sizeof(block*));
        if(gameArray[i] == NULL)
        {
            fprintf(stderr, "Could not allocate memory for gameArray Rows.\n");
        }
    }


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

    srand(time(NULL)); //random number generation
    int position = rand() % 8;

    //window loop
    while(!WindowShouldClose())
    {

        posY += 5;
        if(posY > 950) {
            posY = 950;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
                //DrawRectangle(0, 0, 500, 1000, BACKGROUND);
                background();
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


    //cleanup
    for(int i=0; i<20; i++)     //free the gameArray memory
    {
        free(gameArray[i]);
    }
    free(gameArray);

    return 0;

}

// compile command:
// gcc main.c -o game.exe -Wall -lraylib -lGL -lm -lpthread -ldl -lrt -lX11