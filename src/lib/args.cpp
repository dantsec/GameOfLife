#include <iostream>
#include <getopt.h>

#include "../include/constants.hpp"

using namespace std;

void usage() {
    cout << "usage: ./main [OPTIONS]" << endl;
    cout << "   -h, --help\t\t" << "Print this help and exit." << endl;
    cout << "   -r, --rows\t\t" << "Set quantity of grid rows. DEFAULT=" << ROWS << endl;
    cout << "   -c, --cols\t\t" << "Set quantity of grid cols. DEFAULT=" << COLS << endl;
    cout << "   -g, --gens\t\t" << "Set quantity of gens to play. DEFAULT=" << GENS << endl;
    cout << "   -p, --prob\t\t" << "Set probability to make a cell alive at the start. DEFAULT=" << PROB << endl;
    cout << "   -f, --file\t\t" << "Set a file path to read a grid pattern. You will use a grid from a file." << endl;

    exit(0);
}

void parseArgs(int argc, char *argv[], int &rows, int &cols, int &gens, int &prob, string &filePath) {
    int helpFlag = 0;

    int opt;

    struct option longopts[] = {
        { "help", no_argument, &helpFlag, 1 },
        { "rows", required_argument, NULL, 'r' },
        { "cols", required_argument, NULL, 'c' },
        { "gens", required_argument, NULL, 'g' },
        { "prob", required_argument, NULL, 'p' },
        { "file", required_argument, NULL, 'f' },
        { 0 }
    };

    // Default values from constants.hpp.
    rows = ROWS;
    cols = COLS;
    gens = GENS;
    prob = PROB;
    filePath = "";

    if (argc <= 1 || helpFlag) {
        usage();
    }

    while ((opt = getopt_long(argc, argv, "hr:c:g:p:f:", longopts, NULL)) != -1) {
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
