#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <limits>

#include "../include/constants.hpp"
#include "../include/creator.hpp"
#include "../include/grid.hpp"
#include "../include/utils.hpp"

using namespace std;

void getGridDimensions(int &rows, int &cols) {
    while (true) {
        cout << "How many rows? ";
        cin >> rows;

        cout << "How many cols? ";
        cin >> cols;

        if (rows <= 0 || cols <= 0) {
            cerr << "Error: Invalid grid dimensions. Rows and columns must be greater than zero." << endl;
            cerr << endl;
        } else {
            break;
        }
    }
}

void getCellType(int &cell) {
    while (true) {
        cout << "What kind of cell you want to create? [0=DEAD, 1=LIVE]: ";
        cin >> cell;

        if (cell != 0 && cell != 1) {
            cerr << "Invalid cell type! Please enter 0 for DEAD or 1 for LIVE." << endl;
            cerr << endl;
        } else {
            break;
        }
    }
}

void getCellPosition(int rows, int cols, int &px, int &py) {
    while (true) {
        cout << "What position of grid? [x y]: ";
        cin >> px >> py;

        if (px < 0 || px >= rows || py < 0 || py >= cols) {
            cerr << "Invalid position! Please enter valid coordinates within the grid." << endl;
            cerr << endl;
        } else {
            break;
        }
    }
}

void editCell(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    cout << "Current Grid: " << endl;
    showGrid(grid);
    cout << endl;

    int cell;
    getCellType(cell);
    cout << endl;

    int px, py;
    getCellPosition(rows, cols, px, py);
    cout << endl;

    grid[px][py] = cell;

    cout << "Current Grid: " << endl;
    showGrid(grid);
    cout << endl;
}

void getFileName(string &fileName) {
    while (true) {
        cout << "What is the name of your pattern? ";
        cin >> fileName;

        if (fileName.empty()) {
            cerr << "Error: Pattern name cannot be empty." << endl;
            cerr << endl;
        } else {
            break;
        }
    }
}

void createFilePath(string &filePath, string &fileName) {
    filePath.append(PATTERNS_PATH);
    filePath.append("/");
    filePath.append(fileName);
    filePath.append(".txt");
}

void saveGridToFile(const vector<vector<int>> grid) {
    string fileName;
    getFileName(fileName);

    string filePath;
    createFilePath(filePath, fileName);

    cout << "> Saving on: " << filePath << endl;

    ofstream outputFile(filePath);

    if (!outputFile.is_open()) {
        cerr << "Error: Could not open file " << filePath << " for writing." << endl;
        exit(EXIT_FAILURE);
    }

    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            outputFile << grid[i][j];

            if (j < cols - 1) {
                outputFile << " ";
            }
        }

        outputFile << endl;
    }

    outputFile.close();

    cout << "> Your pattern file is ready! Try with:" << endl;
    cout << "\t./main -r " << rows << " -c " << cols << " -f " << filePath << endl;
}

void patternCreator() {
    cout << "> Welcome to the Pattern Creator!" << endl;
    cout << "> You can create a custom pattern interactively." << endl;
    cout << "> Please follow the prompts to define your grid and cells." << endl << endl;

    int rows, cols;
    getGridDimensions(rows, cols);
    cout << endl;

    vector<vector<int>> grid(rows, vector<int>(cols, 0));

    while (true) {
        editCell(grid);

        // Clear input buffer before prompting for finish.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(!confirmWithDefault("Finish? [y/N]: ", 'N')) {
            cout << endl;
            break;
        }

        cout << endl;
    }

    saveGridToFile(grid);

    exit(EXIT_SUCCESS);
}
