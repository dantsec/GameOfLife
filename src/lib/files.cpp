#include <fstream>
#include <iostream>
#include <vector>

#include "../include/files.hpp"
#include "../include/constants.hpp"

using namespace std;

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
    filePath = string(PATTERNS_PATH) + "/" + fileName + ".txt";
}

void writeGridToFile(vector<vector<int>> grid, string filePath) {
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
}

void readGridFromFile(vector<vector<int>>& grid, string& filePath) {
    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file " << filePath << " for reading." << endl;
        exit(EXIT_FAILURE);
    }

    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inputFile >> grid[i][j];
        }
    }

    inputFile.close();
}

void readCoordinateFromFile(vector<vector<int>>& grid, string& filePath) {
    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file " << filePath << " for reading." << endl;
        exit(EXIT_FAILURE);
    }

    int x, y;
    while (inputFile >> x >> y) {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
            grid[x][y] = ALIVE_INT;
        } else {
            cerr << "Warning: Coordinate (" << x << ", " << y << ") is out of bounds for the grid." << endl;
        }
    }

    inputFile.close();
}

void saveGridToFile(vector<vector<int>> grid, string filePath) {
    cout << "> Saving on: " << filePath << endl;

    writeGridToFile(grid, filePath);

    cout << "> Your pattern file is ready! Try with:" << endl;
    cout << "\t./main -r " << grid.size() << " -c " << grid[0].size() << " -f " << filePath << endl;
}
