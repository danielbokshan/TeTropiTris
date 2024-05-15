#ifndef SPAWN_SHAPES_H
#define SPAWN_SHAPES_H
#include "include/raylib.h"

//color definitions
#define BACKGROUND (Color){103, 128, 159, 255}
#define PALEPINK (Color){255, 179, 186, 255}
#define PALEYELLOW (Color){255, 255, 186, 255}
#define PALEPURPLE (Color){199, 163, 255, 255}
#define PALEORANGE (Color){255, 223, 186, 255}
#define PALEGREEN (Color) {186, 255, 201, 255}
#define LIGHTBLUE (Color){135, 206, 235, 255}
#define PALEGRAY (Color) {190, 190, 190, 255}


//global variables & initializations
extern int idGlobal; //shape ids - counter
extern int moving; //current moving shape - boolean (0=false)

//block struct that keeps track of each cell in the game grid
typedef struct {
    int id; //unique id will pair it to a tetromino - -1 means empty
    int locked;
    Color color; //color
    int moved; //for timestep function - checks to make sure shapes aren't moved twice in 1 step
} block;

//spawn functions for each game piece type
void drawL(block array[10][20]);
void drawLR(block array[10][20]);
void drawZ(block array[10][20]);
void drawZR(block array[10][20]);
void drawO(block array[10][20]);
void drawI(block array[10][20]);
void drawT(block array[10][20]);

#endif