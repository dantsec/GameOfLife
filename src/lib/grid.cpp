#include <iostream>
#include <vector>
#include <cstdlib>

#include "../include/constants.hpp"
#include "../include/grid.hpp"

using namespace std;

void createGrid(vector<vector<int>>* GRID, int prob) {
    int rows = GRID->size();
    int cols = (*GRID)[0].size();

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            (*GRID)[i][j] = (rand() % 100 < prob) ? ALIVE_INT : DEAD_INT;
        }
    }
}

void showGrid(vector<vector<int>> GRID) {
    int rows = GRID.size();
    int cols = GRID[0].size();

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << (GRID[i][j] == ALIVE_INT ? ALIVE_CHR : DEAD_CHR);
        }

        cout << endl;
    }
}
