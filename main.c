#include "include/raylib.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//colors

#define BACKGROUND (Color){103, 128, 159, 255}
#define PALEPINK (Color){255, 179, 186, 255}
#define PALEYELLOW (Color){255, 255, 186, 255}
#define PALEPURPLE (Color){199, 163, 255, 255}
#define PALEORANGE (Color){255, 223, 186, 255}
#define PALEGREEN (Color) {186, 255, 201, 255}
//#define PALEBLUE (Color) {186, 255, 255, 255}
#define LIGHTBLUE (Color){135, 206, 235, 255}
#define PALEGRAY (Color) {190, 190, 190, 255}

//global variables & initializations
typedef struct {
    int id; //unique id will pair it to a tetromino - -1 means empty
    int locked;
    Color color; //color
} block;

int idGlobal = 0;

//game helper functions

int calculatePixel(int arrayIndex) //converts from gameArray index to pixel for rendering
{
    return arrayIndex * 50;
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

//functions to draw each shape

void drawL(block array[10][20]) //draws L at the top of the screen as a new shape
{
    array[4][0].id = idGlobal;
    array[4][0].locked = 0;
    array[4][0].color = LIGHTBLUE;

    array[5][0].id = idGlobal;
    array[5][0].locked = 0;
    array[5][0].color = LIGHTBLUE;

    array[6][0].id = idGlobal;
    array[6][0].locked = 0;
    array[6][0].color = LIGHTBLUE;

    array[6][1].id = idGlobal;
    array[6][1].locked = 0;
    array[6][1].color = LIGHTBLUE;
    printf("idGlobal: %d\n", idGlobal);
    idGlobal++;
}

void drawLR(block array[10][20])
{
    array[4][0].id = idGlobal;
    array[4][0].locked = 0;
    array[4][0].color = PALEPINK;

    array[4][1].id = idGlobal;
    array[4][1].locked = 0;
    array[4][1].color = PALEPINK;

    array[5][0].id = idGlobal;
    array[5][0].locked = 0;
    array[5][0].color = PALEPINK;

    array[6][0].id = idGlobal;
    array[6][0].locked = 0;
    array[6][0].color = PALEPINK;
    idGlobal++;
}

void drawZ(block array[10][20])
{
    array[4][0].id = idGlobal;
    array[4][0].locked = 0;
    array[4][0].color = PALEPURPLE;

    array[5][0].id = idGlobal;
    array[5][0].locked = 0;
    array[5][0].color = PALEPURPLE;

    array[4][1].id = idGlobal;
    array[4][1].locked = 0;
    array[4][1].color = PALEPURPLE;

    array[3][1].id = idGlobal;
    array[3][1].locked = 0;
    array[3][1].color = PALEPURPLE;
    idGlobal++;
}

void drawZR(block array[10][20])
{
    array[3][0].id = idGlobal;
    array[3][0].locked = 0;
    array[3][0].color = PALEYELLOW;

    array[4][0].id = idGlobal;
    array[4][0].locked = 0;
    array[4][0].color = PALEYELLOW;

    array[4][1].id = idGlobal;
    array[4][1].locked = 0;
    array[4][1].color = PALEYELLOW;

    array[5][1].id = idGlobal;
    array[5][1].locked = 0;
    array[5][1].color = PALEYELLOW;
    idGlobal++;
}

void drawO(block array[10][20])
{
    array[4][0].id = idGlobal;
    array[4][0].locked = 0;
    array[4][0].color = PALEGREEN;

    array[4][1].id = idGlobal;
    array[4][1].locked = 0;
    array[4][1].color = PALEGREEN;

    array[5][0].id = idGlobal;
    array[5][0].locked = 0;
    array[5][0].color = PALEGREEN;

    array[5][1].id = idGlobal;
    array[5][1].locked = 0;
    array[5][1].color = PALEGREEN;
    idGlobal++;
}

void drawI(block array[10][20])
{
    array[3][0].id = idGlobal;
    array[3][0].locked = 0;
    array[3][0].color = PALEORANGE;

    array[4][0].id = idGlobal;
    array[4][0].locked = 0;
    array[4][0].color = PALEORANGE;

    array[5][0].id = idGlobal;
    array[5][0].locked = 0;
    array[5][0].color = PALEORANGE;

    array[6][0].id = idGlobal;
    array[6][0].locked = 0;
    array[6][0].color = PALEORANGE;
    idGlobal++;
}

void drawT(block array[10][20])
{
    array[4][0].id = idGlobal;
    array[4][0].locked = 0;
    array[4][0].color = PALEGRAY;

    array[5][0].id = idGlobal;
    array[5][0].locked = 0;
    array[5][0].color = PALEGRAY;

    array[6][0].id = idGlobal;
    array[6][0].locked = 0;
    array[6][0].color = PALEGRAY;

    array[5][1].id = idGlobal;
    array[5][1].locked = 0;
    array[5][1].color = PALEGRAY;
    idGlobal++;
}

//pick a random shape drawing function
void spawnShape(block array[10][20])
{
    srand(time(NULL));
    int num = rand() % 8;
    if(num == 0) {
        drawL(array); //spawn L
    } else if(num == 1) {
        drawLR(array); //spawn L Reversed
    } else if(num == 2) {
        drawZ(array); //spawn Z
    } else if(num == 3) {
        drawZR(array); //spawn Z Reversed
    } else if(num == 4) {
        drawO(array); //spawn O
    } else if(num == 5) {
        drawI(array); //spawn I
    } else if(num == 6) {
        drawT(array); //spawn T
    }
}

void deleteRow(block array[10][20], int row) //slides gameboard above cleared row down to fill it - takes in a pointer to a row of 10 cols
{
    //shift above rows down
    for(int i=row; i>0; i--)
    {
        for(int j=1; j<10; j++)
        {
            array[i][j] = array[i][j-1]; //shift remaining blocks down
        }
    }

    //reinitialize first row of structs to fill in for the ones that moved down
    for(int i=0; i<10; i++)
    {
        //reset to background color, no id, and locked status
        array[i][0].color = BACKGROUND;
        array[i][0].id = -1;
        array[i][0].locked = 1;
    }
}

void timeStep(block array[10][20])
{
    for(int j=1; j<20; j+=1)
    {
        for(int i=0; i<10; i++)
        {
            if(array[i][j-1].locked == 0)
            {
                //shift unlocked blocks down
                array[i][j].color = array[i][j-1].color;
                array[i][j].id = array[i][j-1].id;
                array[i][j].locked = array[i][j-1].locked;

                // change above blocks back to background
                array[i][j-1].color = BACKGROUND;
                array[i][j-1].id = -1;
                array[i][j-1].locked = 1;

                //LOGIC ERROR HERE
            }
        }
    }
}


//main function
int main()
{

    //create and allocate memory for the game board - 10rows x 20cols
    block gameArray[10][20];

    for(int j=0; j<20; j++) 
    {
        for(int i=0; i<10; i++)
        {
            //initialize to blank squares with background color and unattached id
            gameArray[i][j].color = BACKGROUND;
            gameArray[i][j].id = -1;
            gameArray[i][j].locked = 1;
        }
    }

    //initialize textures and main stage + settings
    InitWindow(900, 1000, "New window");
    SetTargetFPS(60);
    float frameCounterFloat = 0.;
    int frameCounterInt = 0;
    int lastFrame = 0;

    // srand(time(NULL)); //random number generation
    // int position = rand() % 8;

    //window loop
    while(!WindowShouldClose())
    {
        //time logic
        frameCounterFloat += GetFrameTime();
        frameCounterInt = frameCounterFloat;
        printf("FrameCounterInt: %d\n", frameCounterInt);
        if(frameCounterInt - lastFrame > 0)
        {
            timeStep(gameArray);
            lastFrame = frameCounterInt;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            //background(); //draw background
            
            for(int j=0; j<20; j++)
            {
                for(int i=0; i<10; i++)
                {
                    //render each block in the gameArray
                    DrawRectangle(calculatePixel(i), calculatePixel(j), 50, 50, gameArray[i][j].color);
                }
            }
            if(IsKeyPressed(KEY_SPACE)) {
                spawnShape(gameArray);
            }
        EndDrawing();
    }
    CloseWindow();

    return 0;

}

// compile command:
// gcc main.c -o game.exe -Wall -lraylib -lGL -lm -lpthread -ldl -lrt -lX11