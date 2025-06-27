#include <iostream>
#include <vector>
#include <chrono>

#include "./include/constants.hpp"
#include "./include/grid.hpp"
#include "./include/rule.hpp"
#include "./include/args.hpp"
#include "./include/creator.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    srand(time(NULL));

    /**
     * Create and parse previous necessary vars.
     */
    int rows,
        cols,
        gens,
        prob,
        mode;

    string filePath;

    parseArgs(argc, argv, rows, cols, gens, prob, filePath, mode);

    /**
     * Enter in the pattern creator mode.
     */
    if (mode == CREATOR_MODE) {
        patternCreator();
    }

    /**
     * Create and populate the grid.
     */
    vector<vector<int>> grid(rows, vector<int>(cols));

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
