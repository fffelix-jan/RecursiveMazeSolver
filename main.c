/**
 * Recursive Maze Solver
 * Copyright (c) 2022 Felix An
 * https://www.felixan.tk/
 * Licensed under the MIT License: https://opensource.org/licenses/MIT
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Coordinate.h"
#include "Maze.h"
#include "MazeImport.h"
#include "MazeCharacter.h"
#include "MazeLimit.h"
#include "MazeSolver.h"

int main(int argc, char **argv)
{
    puts("Recursive Maze Solver");
    puts("Copyright (c) 2022 Felix An");
    puts("https://www.felixan.tk/");
    puts("Licensed under the MIT License: https://opensource.org/licenses/MIT\n");
    printf("Wall character: '%c'\n", WALL_CHAR);
    printf("Air character: '%c'\n", AIR_CHAR);
    printf("Path character: '%c'\n\n", PATH_CHAR);
    puts("Usage: RecursiveMazeSolver <mazeFilename> <startingX> <startingY> <endingX> <endingY> [show/hide] [saveFilename]\n");

    // Check if there are at least two command-line arguments (i.e. the file name of the maze is provided). If not, exit the program with an error.
    if (argc < 6)
    {
        puts("ERROR: You must provide the file name of the maze to solve, the starting coordinates and the ending coordinates as arguments! Exiting.\n");
        return 0;
    }

    // Check if the maze file exists.
    if (access(argv[1], F_OK) != 0)
    {
        puts("ERROR: The file specified does not exist! Exiting.\n");
        return 0;
    }

    // Create an instance of Maze to store the imported maze.
    Maze inMaze;

    // Import the maze from the file.
    FILE *mazeFile = fopen(argv[1], "r");
    if (!importMaze(&inMaze, mazeFile))
    {
        printf("ERROR: Failed to import the maze! Make sure that the maze does not exceed %d rows and %d columns.", MAZE_LIMIT_Y, MAZE_LIMIT_X);
        return 0;
    }

    // Create the coordinates of the start and end.
    Coordinate startCoord;
    startCoord.x = atoi(argv[2]);
    startCoord.y = atoi(argv[3]);

    Coordinate endCoord;
    endCoord.x = atoi(argv[4]);
    endCoord.y = atoi(argv[5]);

    // Save whether the user wants to see the maze while it's being solved.
    bool showSolve = false;
    if (argc > 6 && strcmp(argv[6], "show") == 0)
    {
        showSolve = true;
    }

    // Solve the maze.
    if (solveMaze(&inMaze, startCoord.x, startCoord.y, endCoord.x, endCoord.y, showSolve))
    {
        puts("Maze solved successfully.");

        // Print the maze after it is solved.
        printMaze(stdout, &inMaze);

        // If the user wants the maze saved, save it to a file.
        if (argc > 7)
        {
            FILE *saveFile = fopen(argv[7], "w");
            printMaze(saveFile, &inMaze);
            printf("Solved maze saved in %s.\n", argv[7]);
        }
    }
    else
    {
        puts("ERROR: Cannot solve maze.");
    }

    return 0;
}
