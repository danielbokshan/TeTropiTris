#include "include/raylib.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "spawnshapes.h"

int gameOver = 0;

// game helper functions
int calculatePixel(int arrayIndex) // converts from gameArray index to pixel for rendering
{
    return arrayIndex * 50;
}

int rowFull(block row[10]) // checks if a given row is full - takes in a pointer to a row of 10 cols
{
    for (int i = 0; i < 10; i++)
    {
        if (row[i].id != -1)
        {
            return 0; // false.
        }
    }
    return 1; // row is full (true).
}

void spawnShape(block array[10][20]) // pick a random shape to spawn
{
    srand(time(NULL));
    int num = rand() % 8;
    if (num == 0)
    {
        drawL(array); // spawn L
    }
    else if (num == 1)
    {
        drawLR(array); // spawn L Reversed
    }
    else if (num == 2)
    {
        drawZ(array); // spawn Z
    }
    else if (num == 3)
    {
        drawZR(array); // spawn Z Reversed
    }
    else if (num == 4)
    {
        drawO(array); // spawn O
    }
    else if (num == 5)
    {
        drawI(array); // spawn I
    }
    else if (num == 6)
    {
        drawT(array); // spawn T
    }
}

void deleteRow(block array[10][20], int row) // slides gameboard above cleared row down to fill it - takes in a pointer to a row of 10 cols
{
    // shift above rows down
    for (int i = row; i > 0; i--)
    {
        for (int j = 1; j < 10; j++)
        {
            array[i][j] = array[i][j - 1]; // shift remaining blocks down
        }
    }

    // reinitialize first row of structs to fill in for the ones that moved down
    for (int i = 0; i < 10; i++)
    {
        // reset to background color, no id, and locked status
        array[i][0].color = BACKGROUND;
        array[i][0].id = -1;
        array[i][0].locked = 1;
    }
}

// shift time 1 tick forward and calculate all necessary processes for collisions and motions
void timeStep(block array[10][20])
{
    for (int j = 19; j > 0; j--)
    {
        for (int i = 0; i < 10; i++)
        {
            if (array[i][j - 1].locked == 0 && array[i - 1][j - 1].moved == 0)
            {
                // shift unlocked blocks down
                array[i][j].color = array[i][j - 1].color;
                array[i][j].id = array[i][j - 1].id;
                array[i][j].locked = array[i][j - 1].locked;

                // change above blocks back to background
                array[i][j - 1].color = BACKGROUND;
                array[i][j - 1].id = -1;
                array[i][j - 1].locked = 1;

                array[i][j].moved = 1;
            }
        }
    }

    // reset moved variable to 0
    for (int j = 1; j < 20; j += 1)
    {
        for (int i = 0; i < 10; i++)
        {
            array[i][j].moved = 0;
        }
    }
}

// main function
int main()
{

    // create and allocate memory for the game board - 10rows x 20cols
    block gameArray[10][20];

    for (int j = 0; j < 20; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            // initialize to blank squares
            gameArray[i][j].color = BACKGROUND; // bg color
            gameArray[i][j].id = -1;            // no id
            gameArray[i][j].locked = 1;         // locked status
            gameArray[i][j].moved = 0;          // not moved
        }
    }

    // initialize textures and main stage + settings
    InitWindow(900, 1000, "New window");
    SetTargetFPS(60);
    float frameCounterFloat = 0.;
    int frameCounterInt = 0;
    int lastFrame = 0;

    // window loop
    while (!WindowShouldClose())
    {
        // time logic
        frameCounterFloat += GetFrameTime();
        frameCounterInt = frameCounterFloat; // cast to a whole number
        if (lastFrame % 7 == 0)
        {
            spawnShape(gameArray);
        }
        if (frameCounterInt - lastFrame > 0)
        {
            timeStep(gameArray);
            lastFrame = frameCounterInt;
        }

        BeginDrawing(); // everything in here continuously renders the screen
        ClearBackground(RAYWHITE);
        for (int j = 0; j < 20; j++)
        {
            for (int i = 0; i < 10; i++)
            {
                // render each block in the gameArray based on block info
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