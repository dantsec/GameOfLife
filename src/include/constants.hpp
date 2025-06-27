#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

/**
 * @brief Grid dimensions.
 *
 */
#define ROWS        10
#define COLS        10

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
#define PROB        80

/**
 * @brief Amount of generations to simulate.
 *
 */
#define GENS        5

/**
 * @brief Possible modes of simulation.
 *
 */
#define ITERATIVE_MODE 1
#define NORMAL_MODE    0

#endif // CONSTANTS_HPP
