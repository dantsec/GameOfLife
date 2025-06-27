#include <iostream>
#include <vector>
#include <chrono>

#include "./include/grid.hpp"
#include "./include/rule.hpp"
#include "./include/args.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    srand(time(NULL));

    /**
     * Parse and create necessary vars.
     */
    int rows,
        cols,
        gens,
        prob,
        mode;

    string filePath;

    parseArgs(argc, argv, rows, cols, gens, prob, filePath, mode);

    vector<vector<int>> grid(rows, vector<int>(cols));

    /**
     * Populate the grid.
     */
    filePath.empty()
        ? createRandomGrid(&grid, prob)
        : createGridFromFile(&grid, filePath);

    /**
     * Compute amount of time taken to simulate.
     */
    auto start = chrono::high_resolution_clock::now();

    simulate(&grid, gens, mode);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    double elapsed = duration.count() / 1000.0;

    cout << "Elapsed time: " << elapsed << " seconds." << endl;

    return 0;
}
