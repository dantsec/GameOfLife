#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define ROWS    20
#define COLS    20

#define ALIVE_INT   1
#define ALIVE_CHR   '#'
#define DEAD_INT    0
#define DEAD_CHR    '.'

#define PROB    30

#define GENS    3

using namespace std;

void createGrid(vector<vector<int>>* GRID) {
    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLS; j++) {
            if (rand() % 100 < PROB) {
                (*GRID)[i][j] = ALIVE_INT;
            } else {
                (*GRID)[i][j] = DEAD_INT;
            }
        }
    }
}

void showGrid(vector<vector<int>> GRID) {
    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLS; j++) {
            cout << (GRID[i][j] == ALIVE_INT ? ALIVE_CHR : DEAD_CHR);
        }

        cout << endl;
    }
}

void applyRule(vector<vector<int>>* CURR_GRID, vector<vector<int>>* NEXT_GRID, int ROW, int COL) {
    int currCell = (*CURR_GRID)[ROW][COL];

    int neighboursSum =
        + ((ROW != 0 && COL != 0)                ? (*CURR_GRID)[ROW - 1][COL - 1] : 0)      \
        + ((ROW != 0)                            ? (*CURR_GRID)[ROW - 1][COL]     : 0)      \
        + ((ROW != 0 && COL != COLS - 1)         ? (*CURR_GRID)[ROW - 1][COL + 1] : 0)      \
                                                                                            \
        + ((COL != 0)                            ? (*CURR_GRID)[ROW][COL - 1]     : 0)      \
        + ((COL != COLS - 1)                     ? (*CURR_GRID)[ROW][COL + 1]     : 0)      \
                                                                                            \
        + ((COL != 0 && ROW != ROWS - 1)         ? (*CURR_GRID)[ROW + 1][COL - 1] : 0)      \
        + ((ROW != ROWS - 1)                     ? (*CURR_GRID)[ROW + 1][COL]     : 0)      \
        + ((COL != COLS - 1 && ROW != ROWS - 1)  ? (*CURR_GRID)[ROW + 1][COL + 1] : 0);

    if (currCell == DEAD_INT) {
        (*NEXT_GRID)[ROW][COL] = (neighboursSum == 3) ? ALIVE_INT : DEAD_INT;
    } else {
        (*NEXT_GRID)[ROW][COL] = (neighboursSum < 2 || neighboursSum > 3) ? DEAD_INT : ALIVE_INT;
    }
}

int main() {
    srand(time(NULL));

    vector<vector<int>> GRID(ROWS, vector<int>(COLS));
    vector<vector<int>> NEXT(ROWS, vector<int>(COLS));

    createGrid(&GRID);

    for (int gen = 1; gen <= GENS; gen++) {
        cout << "Generation #" << gen << ": " << endl;

        showGrid(GRID);

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                applyRule(&GRID, &NEXT, i, j);
            }
        }

        GRID = NEXT;

        cout << endl;
    }

    return 0;
}

/**
 * g++ -std=c++11 -O2 -Wall cell.cpp -o cell
 * ./cell
 */
/**
Toda célula morta com exatamente três vizinhos vivos torna-se viva (nascimento).
Toda célula viva com dois ou três vizinhos vivos permanece viva
Toda célula viva com menos de dois vizinhos vivos morre por isolamento.
Toda célula viva com mais de três vizinhos vivos morre por superpopulação.
 */

