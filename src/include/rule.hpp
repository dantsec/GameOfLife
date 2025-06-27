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
 * @param vector<vector<int>>*  Pointer to the current grid.
 * @param vector<vector<int>>*  Pointer to the next grid where the results will be stored.
 * @param int                   The row index of the cell being processed.
 * @param int                   The column index of the cell being processed.
 *
 * @return void
 */
void applyRule(vector<vector<int>>*, vector<vector<int>>*, int, int);

/**
 * @brief Simulates the rule in the grid.
 *
 * @param vector<vector<int>>*  Pointer to the current grid.
 * @param int                   Number of generations to simulate.
 *
 * @return void
 */
void simulate(vector<vector<int>>*, int);

#endif // RULE_HPP
