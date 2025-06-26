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

    createGrid(&GRID);

    simulate(&GRID);

    return 0;
}
