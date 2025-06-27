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

    // Compute amount of time taken to simulate.
    clock_t start = clock();
    simulate(&grid, gens);
    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    cout << "Elapsed time: " << elapsed << " seconds." << endl;

    return 0;
}
