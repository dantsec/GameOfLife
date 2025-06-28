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
 * @brief Get filename from user input.
 *
 * Prompts the user to enter a name for their pattern file.
 *
 * @param std::string&  fileName    Reference to store the filename.
 *
 * @return void
 */
void getFileName(std::string &fileName);

/**
 * @brief Create full file path for pattern file.
 *
 * Constructs the complete file path by combining the patterns directory,
 * filename, and .txt extension.
 *
 * @param std::string&  filePath    Reference to store the complete file path.
 * @param std::string&  fileName    Reference to the filename.
 *
 * @return void
 */
void createFilePath(std::string &filePath, std::string &fileName);

/**
 * @brief Save grid to a file.
 *
 * Writes the grid to a text file in the specified format where 1 represents
 * alive cells and 0 represents dead cells, with spaces between values.
 *
 * @param std::vector<std::vector<int>>    grid    The grid to save to file.
 *
 * @return void
 */
void saveGridToFile(const std::vector<std::vector<int>> grid);

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
