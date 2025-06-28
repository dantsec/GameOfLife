#ifndef CREATOR_HPP
#define CREATOR_HPP

#include <vector>

/**
 * @brief Get grid dimensions from user input with validation.
 *
 * Prompts the user for the number of rows and columns, validates the input,
 * and ensures both values are greater than zero.
 *
 * @param int&  rows    Reference to store the number of rows.
 * @param int&  cols    Reference to store the number of columns.
 *
 * @return void
 */
void getGridDimensions(int &rows, int &cols);

/**
 * @brief Get cell type from user input with validation.
 *
 * Prompts the user to select a cell type (0 for DEAD, 1 for LIVE) and
 * validates the input to ensure it's either 0 or 1.
 *
 * @param int&  cell    Reference to store the selected cell type.
 *
 * @return void
 */
void getCellType(int &cell);

/**
 * @brief Get cell position from user input with validation.
 *
 * Prompts the user for x and y coordinates and validates that they are
 * within the grid boundaries.
 *
 * @param int   rows    The maximum number of rows in the grid.
 * @param int   cols    The maximum number of columns in the grid.
 * @param int&  px      Reference to store the x coordinate.
 * @param int&  py      Reference to store the y coordinate.
 *
 * @return void
 */
void getCellPosition(int rows, int cols, int &px, int &py);

/**
 * @brief Get the mode of operation from user input.
 *
 * Prompts the user to select a mode of operation and validates the input.
 *
 * @param int&  mode    Reference to store the selected mode.
 *
 * @return void
 */
void getMode(int &mode);

/**
 * @brief Get the sub-mode of operation from user input.
 *
 * Prompts the user to select a sub-mode of operation and validates the input.
 *
 * @param int&  subMode    Reference to store the selected sub-mode.
 *
 * @return void
 */
void getSubMode(int &subMode);

/**
 * @brief Edit a single cell in the grid interactively.
 *
 * Displays the current grid, prompts the user for cell type and position,
 * updates the grid, and displays the updated grid.
 *
 * @param std::vector<std::vector<int>>&   grid    Reference to the grid to edit.
 *
 * @return void
 */
void editCell(std::vector<std::vector<int>> &grid);

/**
 * @brief Interactive loop for editing grid cells.
 *
 * @param std::vector<std::vector<int>>&   grid    The grid to edit.
 *
 * @return void
 */
void interactiveGridEditing(std::vector<std::vector<int>>& grid);

/**
 * @brief Create a new pattern from scratch.
 *
 * @return void
 */
void createNewPattern();

/**
 * @brief Edit an existing pattern stored in grid format.
 *
 * @return void
 */
void editExistingGridPattern();

/**
 * @brief Edit an existing pattern stored in coordinate format.
 *
 * @return void
 */
void editExistingCoordinatePattern();

/**
 * @brief Main function to create a custom pattern interactively.
 *
 * Orchestrates the entire pattern creation process: gets grid dimensions,
 * allows user to edit cells interactively, and saves the final pattern to a file.
 *
 * @return void
 */
void patternCreator();

#endif // CREATOR_HPP
