#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "./include/constants.hpp"
#include "./include/grid.hpp"
#include "./include/rule.hpp"

using namespace std;

int main() {
    srand(time(NULL));

    vector<vector<int>> GRID(ROWS, vector<int>(COLS));
    vector<vector<int>> NEXT(ROWS, vector<int>(COLS));

    createGrid(&GRID);

    for (int gen = 1; gen <= GENS; gen++) {
        cout << "Generation #" << gen << ": " << endl;

        showGrid(GRID);

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                applyRule(&GRID, &NEXT, i, j);
            }
        }

        GRID = NEXT;

        cout << endl;
    }

    return 0;
}
