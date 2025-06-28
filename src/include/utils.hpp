#ifndef UTILS_HPP
#define UTILS_HPP

/**
 * @brief Clears the console screen.
 *
 * @return void
 */
void clearConsole();

/**
 * @brief Prompts the user for a confirmation with a default option.
 *
 * @param std::string   text            The prompt message to display.
 * @param char          defaultOption   The default option if the user provides no input.
 *
 * @return bool True if text is empty or matches the default option (case insensitive), false otherwise.
 */
bool confirmWithDefault(std::string text, char defaultOption);

#endif // UTILS_HPP
