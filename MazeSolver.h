#ifndef MAZESOLVER_INCLUDED
#define MAZESOLVER_INCLUDED

/**
 * Prints a Maze to the specified stream.
 * @param stream The stream to print to.
 * @param m The maze to print.
 */
void printMaze(FILE* stream, Maze *m);

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
bool solveMaze(Maze *m, int startingX, int startingY, int endingX, int endingY, bool showProgress);

#endif // MAZESOLVER_INCLUDED
