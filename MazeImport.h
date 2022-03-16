#ifndef MAZEIMPORT_INCLUDED
#define MAZEIMPORT_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include "Maze.h"
#include "MazeLimit.h"

/**
 * Functions for importing mazes from files.
 */

/**
 * Imports a maze from a file and writes it to the instance of Maze specified in dest.
 * @param dest The destination instance of Maze to write the maze in.
 * @param source The source file of the maze.
 */
bool importMaze(Maze *dest, FILE *source)
{
    int yPos = 0;
    int xPos = 0;
    char nextChar = getc(source);
    while (true)
    {
        // If the y position exceeds the limit, stop and return that the import was not successful.
        if (yPos >= MAZE_LIMIT_Y - 1)
        {
            dest->xSize = 0;
            dest->ySize = 0;
            return false;
        }


        // If the x position exceeds the limit, stop and return that the import was not successful.
        if (xPos >= MAZE_LIMIT_X)
        {
            dest->xSize = 0;
            dest->ySize = 0;
            return false;
        }

        if (nextChar == '\n' || nextChar == EOF)
        {
            // printf("EOL %d\n", yPos);
            dest->mazeArray[yPos][xPos] = '\0';
            yPos++;
            xPos = 0;

            if (nextChar == EOF) break;
        }
        else
        {
            dest->mazeArray[yPos][xPos] = nextChar;
            xPos++;
            // printf("Written char %c at %d %d\n", nextChar, yPos, xPos - 1);
        }

        nextChar = getc(source);
    }

    dest->ySize = yPos;
    dest->xSize = strlen(dest->mazeArray[0]);
    return true;
}

#endif // MAZEIMPORT_INCLUDED
