#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

using namespace std;

/**
 * @brief Create a grid vector object based on probability.
 *
 * Alive cells are represented by ALIVE_INT and dead cells by DEAD_INT.
 *
 * @param vector<vector<int>>* represents the grid to be created.
 * @param int represents the probability (in percentage) of a cell being alive at the start.
 *
 * @return void
 */
void createGrid(vector<vector<int>>*, int);

/**
 * @brief Show the grid vector object.
 *
 * Alive cells are represented by ALIVE_CHR and dead cells by DEAD_CHR.
 *
 * @param vector<vector<int>> represents the grid to be shown.
 *
 * @return void
 */
void showGrid(vector<vector<int>>);

#endif // GRID_HPP
