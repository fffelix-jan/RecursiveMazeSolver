#ifndef MAZE_INCLUDED
#define MAZE_INCLUDED

#include <stdbool.h>
#include "MazeLimit.h"

/**
 * A struct that stores information about a maze.
 */
typedef struct Maze
{
    char mazeArray[MAZE_LIMIT_Y][MAZE_LIMIT_X];
    int ySize;
    int xSize;
} Maze;

#endif // MAZE_INCLUDED
