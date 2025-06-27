#ifndef ARGS_HPP
#define ARGS_HPP

/**
 * @brief Prints the usage of the program.
 *
 * @return void
 */
void usage();

/**
 * @brief Parses command line arguments.
 *
 * @param int argc Represents the number of command line arguments.
 * @param char *argv[] Represents the command line arguments.
 * @param int rows Represents the number of rows in the grid.
 * @param int cols Represents the number of columns in the grid.
 * @param int gens Represents the number of generations to simulate.
 * @param int prob Represents the probability of a cell being alive at the start.
 *
 * @return void
 */
void parseArgs(int argc, char *argv[], int &rows, int &cols, int &gens, int &prob);

#endif // ARGS_HPP
