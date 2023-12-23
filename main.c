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
    int locked;
    Color color; //color
} block;

int idGlobal = 0;

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

//functions to draw each shape

void drawL(int posY) //draws L at the top of the screen as a new shape
{
    //rewrite this entire function
    int posX = 4;
    if(posY == -101) {
        posY = -100;
    }
    //this isn't gonna work lol - it just needs to update the colors and ids of the blocks around block [4][0]
    DrawRectangle(posX*50, posY, 50, 50, LIGHTBLUE);
    DrawRectangle((posX+1)*50, posY, 50, 50, LIGHTBLUE);
    DrawRectangle((posX+2)*50, posY, 50, 50, LIGHTBLUE);
    DrawRectangle((posX+2)*50, posY-50, 50, 50, LIGHTBLUE);
}

void drawLR()
{

}

void drawZ()
{

}

void drawZR()
{

}

void drawO()
{

}

void drawI()
{

}

void drawT()
{
    
}

//pick a random shape drawing function
void spawnShape()
{
    srand(time(NULL));
    int num = rand() % 8;
    if(num == 0) {
        drawL(); //spawn L
    } else if(num == 1) {
        drawLR();
    } else if(num == 2) {
        drawZ();
    } else if(num == 3) {
        drawZR();
    } else if(num == 4) {
        drawO();
    } else if(num == 5) {
        drawI();
    } else if(num == 6) {
        drawT();
    }
}


void deleteRow(block** shiftArray, int row) //slides gameboard above cleared row down to fill it - takes in a pointer to a row of 10 cols
{
    for(int i=0; i<10; i++)
    {
        //clear the desired row
        shiftArray[row][i].id = -1;
        shiftArray[row][i].color = BACKGROUND;
    }

    //shift above rows down
    for(int i=row; i>0; i--)
    {
        for(int j=1; j<10; j++)
        {
            shiftArray[i][j] = shiftArray[i][j-1]; //shift remaining blocks down
        }
    }

    //reinitialize first row of structs to fill in for the ones that moved down
    for(int i=0; i<10; i++)
    {
        //reset to background color, no id, and locked status
        shiftArray[i][0].color = BACKGROUND;
        shiftArray[i][0].id = -1;
        shiftArray[i][1].locked = 1;
    }
}


//main function
int main()
{

    //create and allocate memory for the game board - 10rows x 20cols
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

    for(int i=0; i<10; i++) 
    {
        for(int j=0; j<20; j++)
        {
            //initialize to blank squares with background color and unattached id
            gameArray[i][j].color = BACKGROUND;
            gameArray[i][j].id = -1;
        }
    }


    //initialize textures and main stage + settings
    int posY = -150;
    InitWindow(900, 1000, "New window");
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
                background(); //draw background
                // DrawRectangle(position*50, posY, 50, 50, LIGHTBLUE);
                // DrawRectangle((position+1)*50, posY, 50, 50, LIGHTBLUE);
                // DrawRectangle((position+2)*50, posY, 50, 50, LIGHTBLUE);
                // DrawRectangle((position+2)*50, posY-50, 50, 50, LIGHTBLUE);
            
            for(int i=0; i<20; i++)
            {
                for(int j=0; j<10; j++)
                {
                    //render each block in the gameArray
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