#ifndef RULE_HPP
#define RULE_HPP

#include <vector>

using namespace std;

/**
 * @brief Applies the rules of the "Game of Life" to a cell in the grid.
 *
 * The rule is:
 *   - Any dead cell with exactly three live neighbours becomes alive (birth).
 *   - Any live cell with two or three live neighbours stays alive.
 *   - Any live cell with fewer than two live neighbours dies (underpopulation).
 *   - Any live cell with more than three live neighbours dies (overpopulation).
 *
 * @param vector<vector<int>>*  currGrid Pointer to the current grid.
 * @param vector<vector<int>>*  nextGrid Pointer to the next grid where the results will be stored.
 * @param int                   row       The row index of the cell being processed.
 * @param int                   col       The column index of the cell being processed.
 *
 * @return void
 */
void applyRule(vector<vector<int>>* currGrid, vector<vector<int>>* nextGrid, int row, int col);

/**
 * @brief Simulates the rule in the grid.
 *
 * @param vector<vector<int>>*  grid Pointer to the current grid.
 * @param int                   gens Number of generations to simulate.
 *
 * @return void
 */
void simulate(vector<vector<int>>* grid, int gens);

#endif // RULE_HPP
