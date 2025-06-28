#ifndef FILES_HPP
#define FILES_HPP

#include <vector>

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
 * @brief Helper function to write grid data to a file.
 *
 * @param std::vector<std::vector<int>>   grid        The grid to write.
 * @param std::string                     filePath    The path to the output file.
 *
 * @return void
 */
void writeGridToFile(std::vector<std::vector<int>> grid, std::string filePath);

/**
 * @brief Helper function to read grid data from a file.
 *
 * @param std::vector<std::vector<int>>&   grid        The grid to populate.
 * @param std::string&                     filePath    The path to the input file.
 *
 * @return void
 */
void readGridFromFile(std::vector<std::vector<int>>& grid, std::string& filePath);

/**
 * @brief Read coordinates from a file and populate the grid.
 *
 * Reads coordinates from a file where each line contains two integers representing coordinates to alive cells.
 *
 * @param std::vector<std::vector<int>>&    grid        The grid to populate with coordinates.
 * @param std::string&                      filePath    The path to the input file containing coordinates.
 *
 * @return void
 */
void readCoordinateFromFile(std::vector<std::vector<int>>& grid, std::string& filePath);

/**
 * @brief Save grid to a file.
 *
 * Writes the grid to a text file in the specified format where 1 represents
 * alive cells and 0 represents dead cells, with spaces between values.
 *
 * @param std::vector<std::vector<int>> grid        The grid to save to file.
 * @param std::string                   filePath    The path to the output file.
 *
 * @return void
 */
void saveGridToFile(std::vector<std::vector<int>> grid, std::string filePath);

#endif // FILES_HPP
