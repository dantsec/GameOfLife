#include <iostream>
#include <getopt.h>

#include "../include/constants.hpp"
#include "../include/args.hpp"

using namespace std;

void usage() {
    cout << "Usage: ./main [OPTIONS]\n\n";

    cout << "Grid Configuration:\n";
    cout << "  -r, --rows <num>\tSet the number of grid rows. Default: " << ROWS << "\n";
    cout << "  -c, --cols <num>\tSet the number of grid columns. Default: " << COLS << "\n";
    cout << "  -f, --file-path <string>\tLoad an initial grid pattern from a file instead of using a randomly generated grid.\n\n";

    cout << "Simulation Settings:\n";
    cout << "  -g, --gens <num>\tSet the number of generations to simulate. Default: " << GENS << "\n";
    cout << "  -p, --prob <num>\tSet the probability (0–100) of a cell being alive at start. Default: " << PROB << "%\n";
    cout << "  -m, --mode <num>\tSet the simulation mode (0: Normal, 1: Iterative, 2: Movie, 3: Creator). Default: " << NORMAL_MODE << "\n\n";

    cout << "General:\n";
    cout << "  -h, --help\t\tShow this help message and exit.\n\n";

    cout << "Notes:\n";
    cout << "  > If no input file is provided with -f/--file-path, a grid will be randomly generated\n";
    cout << "    based on the specified rows, columns, and probability.\n";
    cout << "  > Probability only applies when generating a random grid (i.e., not using -f/--file-path).\n";

    exit(0);
}

void parseArgs(int argc, char *argv[], int &rows, int &cols, int &gens, int &prob, string &filePath, int &mode) {
    int helpFlag = 0;

    int opt;

    struct option longopts[] = {
        { "help", no_argument, &helpFlag, 1 },
        { "rows", required_argument, NULL, 'r' },
        { "cols", required_argument, NULL, 'c' },
        { "gens", required_argument, NULL, 'g' },
        { "prob", required_argument, NULL, 'p' },
        { "file-path", required_argument, NULL, 'f' },
        { "mode", required_argument, NULL, 'm' },
        { 0 }
    };

    // Default values from constants.hpp.
    rows = ROWS;
    cols = COLS;
    gens = GENS;
    prob = PROB;
    filePath = "";
    mode = NORMAL_MODE;

    if (argc <= 1 || helpFlag) {
        usage();
    }

    while ((opt = getopt_long(argc, argv, "hr:c:g:p:f:m:", longopts, NULL)) != -1) {
        switch (opt) {
            case 'r':
                rows = atoi(optarg);

                if (rows <= 0) {
                    cerr << "Error: Invalid number of rows." << endl;
                    exit(1);
                }

                break;
            case 'c':
                cols = atoi(optarg);

                if (cols <= 0) {
                    cerr << "Error: Invalid number of cols." << endl;
                    exit(1);
                }

                break;
            case 'g':
                gens = atoi(optarg);

                if (gens <= 0) {
                    cerr << "Error: Invalid number of generations." << endl;
                    exit(1);
                }

                break;
            case 'p':
                prob = atoi(optarg);

                if (prob < 0 || prob > 100) {
                    cerr << "Error: Invalid probability value. Must be between 0 and 100." << endl;
                    exit(1);
                }

                break;
            case 'f':
                filePath = optarg;
                break;
            case 'm':
                mode = atoi(optarg);

                if (mode != NORMAL_MODE
                    && mode != ITERATIVE_MODE
                    && mode != MOVIE_MODE
                    && mode != CREATOR_MODE
                ) {
                    cerr << "Error: Invalid mode. Must be 0 (Normal), 1 (Iterative), 2 (Movie) or 3 (Pattern Editor)." << endl;
                    exit(1);
                }

                break;
            case 'h':
                usage();
                break;
            case '?':
                cerr << "Use -h or --help for usage information." << endl;
                exit(1);
            default:
                break;
        }
    }
}
