#ifndef MAZEIMPORT_INCLUDED
#define MAZEIMPORT_INCLUDED

/**
 * Functions for importing mazes from files.
 */

/**
 * Imports a maze from a file and writes it to the instance of Maze specified in dest.
 * @param dest The destination instance of Maze to write the maze in.
 * @param source The source file of the maze.
 */
bool importMaze(Maze *dest, FILE *source);

#endif // MAZEIMPORT_INCLUDED
