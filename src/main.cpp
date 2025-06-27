#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "./include/grid.hpp"
#include "./include/rule.hpp"
#include "./include/args.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int rows,
        cols,
        gens,
        prob;

    parseArgs(argc, argv, rows, cols, gens, prob);

    vector<vector<int>> GRID(rows, vector<int>(cols));

    createGrid(&GRID, prob);

    simulate(&GRID, gens);

    return 0;
}
