#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

/**
 * @brief Grid dimensions.
 *
 */
#define ROWS                20
#define COLS                20

/**
 * @brief Cell states.
 *
 */
#define ALIVE_INT           1
#define ALIVE_CHR           '#'
#define DEAD_INT            0
#define DEAD_CHR            '.'

/**
 * @brief Probability of a cell being alive at the start (using random generated grid).
 *
 */
#define PROB                80

/**
 * @brief Amount of generations to simulate.
 *
 */
#define GENS                5

/**
 * @brief Modes of simulation states.
 *
 */
#define NORMAL_MODE         0
#define INTERACTIVE_MODE    1
#define MOVIE_MODE          2
#define CREATOR_MODE        3
#define EDITOR_MODE         4

#define GRID_FORMAT         0
#define COORD_FORMAT        1

#define MOVIE_DELAY         150

/**
 * @brief File settings.
 *
 */
#define PATTERNS_PATH   "./patterns"

#endif // CONSTANTS_HPP
