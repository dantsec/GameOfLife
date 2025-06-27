#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

#include "../include/constants.hpp"
#include "../include/grid.hpp"

using namespace std;

void createRandomGrid(vector<vector<int>>* grid, int prob) {
    int rows = grid->size();
    int cols = (*grid)[0].size();

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            (*grid)[i][j] = (rand() % 100 < prob) ? ALIVE_INT : DEAD_INT;
        }
    }
}

void createGridFromFile(vector<vector<int>>* grid, string filePath) {
    ifstream my_file(filePath);

    if (!my_file) {
        cerr << "Error opening the file." << endl;
        exit(1);
    }

    int rows = grid->size();
    int cols = (*grid)[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int cell; my_file >> cell;

            (*grid)[i][j] = cell;
        }
    }

    my_file.close();
}

void showGrid(vector<vector<int>> grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << (grid[i][j] == ALIVE_INT ? ALIVE_CHR : DEAD_CHR) << " ";
        }

        cout << endl;
    }
}
