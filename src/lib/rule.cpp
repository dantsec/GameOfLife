#include <iostream>
#include <vector>

#include "../include/constants.hpp"
#include "../include/grid.hpp"
#include "../include/rule.hpp"

using namespace std;

void applyRule(vector<vector<int>>* CURR_GRID, vector<vector<int>>* NEXT_GRID, int ROW, int COL) {
    int currCell = (*CURR_GRID)[ROW][COL];

    int rows = CURR_GRID->size();
    int cols = (*CURR_GRID)[0].size();

    int neighboursSum =
        + ((ROW != 0 && COL != 0)                ? (*CURR_GRID)[ROW - 1][COL - 1] : 0)      \
        + ((ROW != 0)                            ? (*CURR_GRID)[ROW - 1][COL]     : 0)      \
        + ((ROW != 0 && COL != cols - 1)         ? (*CURR_GRID)[ROW - 1][COL + 1] : 0)      \
                                                                                            \
        + ((COL != 0)                            ? (*CURR_GRID)[ROW][COL - 1]     : 0)      \
        + ((COL != cols - 1)                     ? (*CURR_GRID)[ROW][COL + 1]     : 0)      \
                                                                                            \
        + ((COL != 0 && ROW != rows - 1)         ? (*CURR_GRID)[ROW + 1][COL - 1] : 0)      \
        + ((ROW != rows - 1)                     ? (*CURR_GRID)[ROW + 1][COL]     : 0)      \
        + ((COL != cols - 1 && ROW != rows - 1)  ? (*CURR_GRID)[ROW + 1][COL + 1] : 0);

    if (currCell == DEAD_INT) {
        (*NEXT_GRID)[ROW][COL] = (neighboursSum == 3) ? ALIVE_INT : DEAD_INT;
    } else {
        (*NEXT_GRID)[ROW][COL] = (neighboursSum < 2 || neighboursSum > 3) ? DEAD_INT : ALIVE_INT;
    }
}

void simulate(vector<vector<int>>* GRID, int gens) {
    int rows = GRID->size();
    int cols = (*GRID)[0].size();

    vector<vector<int>> NEXT(rows, vector<int>(cols));

    for (int gen = 1; gen <= gens; gen++) {
        cout << "Generation #" << gen << ": " << endl;

        showGrid(*GRID);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                applyRule(GRID, &NEXT, i, j);
            }
        }

        *GRID = NEXT;

        cout << endl;
    }
}
