#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "Maze.h"
#include "MazeCharacter.h"
#include "MazeLimit.h"

/**
 * Prints a Maze to the specified stream.
 * @param stream The stream to print to.
 * @param m The maze to print.
 */
void printMaze(FILE* stream, Maze *m)
{
    for (int i = 0; i <= m->ySize; i++)
    {
        fprintf(stream, "%s\n", m->mazeArray[i]);
    }
}

/**
 * Solves a Maze recursively.
 *
 * @param m The Maze to solve.
 * @param startingX The starting x-coordinate.
 * @param startingY The starting y-coordinate.
 * @param endingX The ending x-coordinate.
 * @param endingY The ending y-coordinate.
 * @param showProgress Whether to show the maze being solved in real time on the screen.
 * @return true if the maze was solved successfully, and false otherwise.
 */
bool solveMaze(Maze *m, int startingX, int startingY, int endingX, int endingY, bool showProgress)
{
    // Move forward.
    m->mazeArray[startingY][startingX] = PATH_CHAR;

    if (showProgress)
    {
        printMaze(stdout, m);
        sleep(1);
    }

    // Check if the goal has been reached, and return true if it has been reached.
    if (startingX == endingX && startingY == endingY)
    {
        return true;
    }

    // Solve the maze recursively.
    if (startingX > 0 && m->mazeArray[startingY][startingX - 1] == AIR_CHAR && solveMaze(m, startingX - 1, startingY, endingX, endingY, showProgress))
    {
        return true;
    }
    if (startingX < m->xSize && m->mazeArray[startingY][startingX + 1] == AIR_CHAR && solveMaze(m, startingX + 1, startingY, endingX, endingY, showProgress))
    {
        return true;
    }
    if (startingY > 0 && m->mazeArray[startingY - 1][startingX] == AIR_CHAR && solveMaze(m, startingX, startingY - 1, endingX, endingY, showProgress))
    {
        return true;
    }
    if (startingY < m->ySize && m->mazeArray[startingY + 1][startingX] == AIR_CHAR && solveMaze(m, startingX, startingY + 1, endingX, endingY, showProgress))
    {
        return true;
    }

    // Go back and find another path if path is blocked.
    m->mazeArray[startingY][startingX] = AIR_CHAR;

    if (showProgress)
    {
        printMaze(stdout, m);
        sleep(1);
    }

    // Maze cannot be solved, return false
    return false;
}
