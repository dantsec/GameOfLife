#include <iostream>
#include <vector>
#include <cstdlib>

#include "../include/constants.hpp"
#include "../include/grid.hpp"

using namespace std;

void createGrid(vector<vector<int>>* grid, int prob) {
    int rows = grid->size();
    int cols = (*grid)[0].size();

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            (*grid)[i][j] = (rand() % 100 < prob) ? ALIVE_INT : DEAD_INT;
        }
    }
}

void showGrid(vector<vector<int>> grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << (grid[i][j] == ALIVE_INT ? ALIVE_CHR : DEAD_CHR);
        }

        cout << endl;
    }
}
