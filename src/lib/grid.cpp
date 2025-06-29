#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <limits>

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
        exit(EXIT_FAILURE);
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

void personalizedShowGrid(vector<vector<int>> grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    int rowDigitCount = (rows <= 1) ? 1 : static_cast<int>(floor(log10(rows - 1)) + 1);
    int colDigitCount = (cols <= 1) ? 1 : static_cast<int>(floor(log10(cols - 1)) + 1);

    // Print column headers with proper spacing.
    cout << string(rowDigitCount + 1, ' ');

    for (int j = 0; j < cols; j++) {
        cout << setw(colDigitCount) << j;
        if (j < cols - 1) {
            cout << " ";
        }
    }

    cout << endl;

    for (int i = 0; i < rows; i++) {
        // Print grid with row numbers.
        cout << setw(rowDigitCount) << i << " ";

        for (int j = 0; j < cols; j++) {
            cout << setw(colDigitCount) << (grid[i][j] == DEAD_INT ? DEAD_CHR : ALIVE_CHR);

            if (j < cols - 1) {
                cout << " ";
            }
        }

        cout << endl;
    }
}
