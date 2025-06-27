#ifndef RULE_HPP
#define RULE_HPP

#include <vector>

/**
 * @brief Checks if the user wants to proceed to the next generation.
 *
 * This function prompts the user for input and returns true if the user
 * wants to proceed, or false if the user wants to stop the simulation.
 *
 * @return bool
 */
bool proceedToNextGeneration();

/**
 * @brief Applies the rules of the "Game of Life" to a cell in the grid.
 *
 * The rule is:
 *   - Any dead cell with exactly three live neighbours becomes alive (birth).
 *   - Any live cell with two or three live neighbours stays alive.
 *   - Any live cell with fewer than two live neighbours dies (underpopulation).
 *   - Any live cell with more than three live neighbours dies (overpopulation).
 *
 * @param std::vector<std::vector<int>>*    currGrid Pointer to the current grid.
 * @param std::vector<std::vector<int>>*    nextGrid Pointer to the next grid where the results will be stored.
 * @param int                               row       The row index of the cell being processed.
 * @param int                               col       The column index of the cell being processed.
 *
 * @return void
 */
void applyRule(std::vector<std::vector<int>>* currGrid, std::vector<std::vector<int>>* nextGrid, int row, int col);

/**
 * @brief Simulates the rule in the grid.
 *
 * @param std::vector<std::vector<int>>*    grid Pointer to the current grid.
 * @param int                               gens Number of generations to simulate.
 * @param int                               mode Simulation mode (values are defined in constants.hpp).
 *
 * @return void
 */
void simulate(std::vector<std::vector<int>>* grid, int gens, int mode);

#endif // RULE_HPP
