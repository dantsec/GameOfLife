#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

/**
 * @brief Grid dimensions.
 *
 */
#define ROWS    20
#define COLS    20

/**
 * @brief Cell states.
 *
 */
#define ALIVE_INT   1
#define ALIVE_CHR   '#'
#define DEAD_INT    0
#define DEAD_CHR    '.'

/**
 * @brief Probability of a cell being alive at the start (using random generated grid).
 *
 */
#define PROB    30

/**
 * @brief Amount of generations to simulate.
 *
 */
#define GENS    3

#endif // CONSTANTS_HPP
