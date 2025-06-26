#include <vector>

#include "../include/constants.hpp"
#include "../include/rule.hpp"

using namespace std;

void applyRule(vector<vector<int>>* CURR_GRID, vector<vector<int>>* NEXT_GRID, int ROW, int COL) {
    int currCell = (*CURR_GRID)[ROW][COL];

    int neighboursSum =
        + ((ROW != 0 && COL != 0)                ? (*CURR_GRID)[ROW - 1][COL - 1] : 0)      \
        + ((ROW != 0)                            ? (*CURR_GRID)[ROW - 1][COL]     : 0)      \
        + ((ROW != 0 && COL != COLS - 1)         ? (*CURR_GRID)[ROW - 1][COL + 1] : 0)      \
                                                                                            \
        + ((COL != 0)                            ? (*CURR_GRID)[ROW][COL - 1]     : 0)      \
        + ((COL != COLS - 1)                     ? (*CURR_GRID)[ROW][COL + 1]     : 0)      \
                                                                                            \
        + ((COL != 0 && ROW != ROWS - 1)         ? (*CURR_GRID)[ROW + 1][COL - 1] : 0)      \
        + ((ROW != ROWS - 1)                     ? (*CURR_GRID)[ROW + 1][COL]     : 0)      \
        + ((COL != COLS - 1 && ROW != ROWS - 1)  ? (*CURR_GRID)[ROW + 1][COL + 1] : 0);

    if (currCell == DEAD_INT) {
        (*NEXT_GRID)[ROW][COL] = (neighboursSum == 3) ? ALIVE_INT : DEAD_INT;
    } else {
        (*NEXT_GRID)[ROW][COL] = (neighboursSum < 2 || neighboursSum > 3) ? DEAD_INT : ALIVE_INT;
    }
}
