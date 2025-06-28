#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>

#include "../include/constants.hpp"
#include "../include/creator.hpp"
#include "../include/grid.hpp"
#include "../include/utils.hpp"
#include "../include/files.hpp"

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
        cout << "What kind of cell you want to edit? [0=DEAD, 1=LIVE]: ";
        cin >> cell;

        if (cell != DEAD_INT && cell != ALIVE_INT) {
            cerr << "Invalid choice! Please enter 0 for DEAD or 1 for LIVE." << endl;
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

void getMode(int &mode) {
    while (true) {
        cout << "Do you want to create a new grid or edit an existing one? [3=Create, 4=Edit]: ";
        cin >> mode;

        if (mode != CREATOR_MODE && mode != EDITOR_MODE) {
            cerr << "Invalid choice! Please enter 3 for Create or 4 for Edit." << endl;
            cerr << endl;
        } else {
            break;
        }
    }
}

void getSubMode(int &subMode) {
    while (true) {
        cout << "Your file follows what format? [0=Grid, 1=Coordinates]: ";
        cin >> subMode;

        if (subMode != GRID_FORMAT && subMode != COORD_FORMAT) {
            cerr << "Invalid choice! Please enter 0 for Grid or 1 for Coordinates." << endl;
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
    personalizedShowGrid(grid);
    cout << endl;

    int cell;
    getCellType(cell);
    cout << endl;

    int px, py;
    getCellPosition(rows, cols, px, py);
    cout << endl;

    // Inverted the coordinates to match the grid structure.
    grid[py][px] = cell;

    cout << "Current Grid: " << endl;
    personalizedShowGrid(grid);
    cout << endl;
}

void interactiveGridEditing(vector<vector<int>>& grid) {
    while (true) {
        editCell(grid);

        // Clear input buffer before prompting for finish
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!confirmWithDefault("Finish? [y/N]: ", 'N')) {
            cout << endl;
            break;
        }
        cout << endl;
    }
}

void createNewPattern() {
    int rows, cols;
    getGridDimensions(rows, cols);
    cout << endl;

    vector<vector<int>> grid(rows, vector<int>(cols, 0));

    interactiveGridEditing(grid);

    string fileName;
    getFileName(fileName);

    string filePath;
    createFilePath(filePath, fileName);

    saveGridToFile(grid, filePath);
}

void editExistingGridPattern() {
    string fileName;
    getFileName(fileName);

    string filePath;
    createFilePath(filePath, fileName);

    int rows, cols;
    getGridDimensions(rows, cols);
    cout << endl;

    vector<vector<int>> grid(rows, vector<int>(cols, 0));

    readGridFromFile(grid, filePath);

    interactiveGridEditing(grid);

    saveGridToFile(grid, filePath);
}

void editExistingCoordinatePattern() {
    string fileName;
    getFileName(fileName);

    string filePath;
    createFilePath(filePath, fileName);

    int rows, cols;
    getGridDimensions(rows, cols);
    cout << endl;

    vector<vector<int>> grid(rows, vector<int>(cols, 0));

    readCoordinateFromFile(grid, filePath);
    cout << endl;

    interactiveGridEditing(grid);

    saveGridToFile(grid, filePath);
}

void patternCreator() {
    cout << "> Welcome to the Pattern Creator!" << endl;
    cout << "> You can create or edit a custom pattern interactively." << endl;
    cout << "> Please follow the prompts to define your grid and cells." << endl << endl;

    int mode;
    getMode(mode);
    cout << endl;

    if (mode == CREATOR_MODE) {
        createNewPattern();
    }

    if (mode == EDITOR_MODE) {
        int subMode;
        getSubMode(subMode);
        cout << endl;

        if (subMode == GRID_FORMAT) {
            editExistingGridPattern();
        }

        if (subMode == COORD_FORMAT) {
            editExistingCoordinatePattern();
        }
    }

    exit(EXIT_SUCCESS);
}
