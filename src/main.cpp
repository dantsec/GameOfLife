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

    string filePath;

    parseArgs(argc, argv, rows, cols, gens, prob, filePath);

    vector<vector<int>> grid(rows, vector<int>(cols));

    filePath.empty()
        ? createRandomGrid(&grid, prob)
        : createGridFromFile(&grid, filePath);

    simulate(&grid, gens);

    return 0;
}
