#include <stdio.h>
#include <stdlib.h>
#include "spawnshapes.h"
#include "include/raylib.h"

//declare global variables
int idGlobal = 0;
int moving = 0;

//functions to draw each shape

void drawL(block array[10][20]) //adds L to top of gameArray data structure
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
    idGlobal++;
}

void drawLR(block array[10][20]) //adds reversed L to top of gameArray data structure
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

void drawZ(block array[10][20]) //adds Z to top of gameArray data structure
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

void drawZR(block array[10][20]) //adds reversed Z to top of gameArray data structure
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

void drawO(block array[10][20])//adds O to top of gameArray data structure
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

void drawI(block array[10][20]) //adds I to top of gameArray data structure
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

void drawT(block array[10][20]) //adds T to top of gameArray data structure
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