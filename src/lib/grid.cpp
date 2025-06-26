#include <iostream>
#include <vector>
#include <cstdlib>

#include "../include/constants.hpp"
#include "../include/grid.hpp"

using namespace std;

void createGrid(vector<vector<int>>* GRID) {
    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLS; j++) {
            (*GRID)[i][j] = (rand() % 100 < PROB) ? ALIVE_INT : DEAD_INT;
        }
    }
}

void showGrid(vector<vector<int>> GRID) {
    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLS; j++) {
            cout << (GRID[i][j] == ALIVE_INT ? ALIVE_CHR : DEAD_CHR);
        }

        cout << endl;
    }
}
