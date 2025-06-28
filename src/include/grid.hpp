#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

/**
 * @brief Create a grid vector object based on probability.
 *
 * Alive cells are represented by ALIVE_INT and dead cells by DEAD_INT.
 *
 * @param vector<vector<int>>*  grid represents the grid to be created.
 * @param int                   prob represents the probability (in percentage) of a cell being alive at the start.
 *
 * @return void
 */
void createRandomGrid(std::vector<std::vector<int>>* grid, int prob);

/**
 * @brief Create a grid vector object based on a file path.
 *
 * @param std::vector<std::vector<int>>*    grid        represents the grid to be created.
 * @param std::string                       filePath    represents the file path to read the grid pattern from.
 */
void createGridFromFile(std::vector<std::vector<int>>* grid, std::string filePath);

/**
 * @brief Show the grid vector object.
 *
 * Alive cells are represented by ALIVE_CHR and dead cells by DEAD_CHR.
 *
 * @param vector<vector<int>> grid represents the grid to be shown.
 *
 * @return void
 */
void showGrid(std::vector<std::vector<int>> grid);

/**
 * @brief Show the grid vector object with personalized formatting.
 *
 * Show index and coordinates of each cell.
 *
 * @param vector<vector<int>> grid represents the grid to be shown.
 *
 * @return void
 */
void personalizedShowGrid(std::vector<std::vector<int>> grid);

#endif // GRID_HPP
