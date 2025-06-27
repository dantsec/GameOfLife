#include <iostream>
#include <vector>

#include "../include/constants.hpp"
#include "../include/grid.hpp"
#include "../include/rule.hpp"

using namespace std;

void applyRule(vector<vector<int>>* currGrid, vector<vector<int>>* nextGrid, int row, int col) {
    int currCell = (*currGrid)[row][col];

    int rows = currGrid->size();
    int cols = (*currGrid)[0].size();

    int neighboursSum =
        + ((row != 0 && col != 0)                ? (*currGrid)[row - 1][col - 1] : 0)   \
        + ((row != 0)                            ? (*currGrid)[row - 1][col]     : 0)   \
        + ((row != 0 && col != cols - 1)         ? (*currGrid)[row - 1][col + 1] : 0)   \
                                                                                        \
        + ((col != 0)                            ? (*currGrid)[row][col - 1]     : 0)   \
        + ((col != cols - 1)                     ? (*currGrid)[row][col + 1]     : 0)   \
                                                                                        \
        + ((col != 0 && row != rows - 1)         ? (*currGrid)[row + 1][col - 1] : 0)   \
        + ((row != rows - 1)                     ? (*currGrid)[row + 1][col]     : 0)   \
        + ((col != cols - 1 && row != rows - 1)  ? (*currGrid)[row + 1][col + 1] : 0);

    if (currCell == DEAD_INT) {
        (*nextGrid)[row][col] = (neighboursSum == 3) ? ALIVE_INT : DEAD_INT;
    } else {
        (*nextGrid)[row][col] = (neighboursSum < 2 || neighboursSum > 3) ? DEAD_INT : ALIVE_INT;
    }
}

void simulate(vector<vector<int>>* grid, int gens) {
    int rows = grid->size();
    int cols = (*grid)[0].size();

    vector<vector<int>> next(rows, vector<int>(cols));

    for (int gen = 0; gen < gens; gen++) {
        cout << "Generation #" << gen << ": " << endl;

        showGrid(*grid);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                applyRule(grid, &next, i, j);
            }
        }

        *grid = next;

        cout << endl;
    }
}
