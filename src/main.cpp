#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "./include/constants.hpp"
#include "./include/grid.hpp"
#include "./include/rule.hpp"
#include "./include/args.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // srand(time(NULL));

    int rows,
        cols,
        gens,
        prob;

    parseArgs(argc, argv, rows, cols, gens, prob);

    cout << "Rows: " << rows << endl;
    cout << "Cols: " << cols << endl;
    cout << "Generations: " << gens << endl;
    cout << "Probability: " << prob << "%" << endl;

    // vector<vector<int>> GRID(ROWS, vector<int>(COLS));

    // createGrid(&GRID);

    // simulate(&GRID);

    return 0;
}
