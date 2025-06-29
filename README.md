<p align="center">
    <img src="https://hackerlogo.com/images/HackerLogo.png">
</p>

<br>

<p align="center">
    <img src="https://img.shields.io/github/license/dantsec/GameOfLife?color=black&logo=github&logoColor=white&style=for-the-badge">
    <img src="https://img.shields.io/github/issues/dantsec/GameOfLife?color=black&logo=github&logoColor=white&style=for-the-badge">
    <img src="https://img.shields.io/github/stars/dantsec/GameOfLife?color=black&label=STARS&logo=github&logoColor=white&style=for-the-badge">
    <img src="https://img.shields.io/github/forks/dantsec/GameOfLife?color=black&logo=github&logoColor=white&style=for-the-badge">
    <img src="https://img.shields.io/github/languages/code-size/dantsec/GameOfLife?color=black&logo=github&logoColor=white&style=for-the-badge">
</p>

# Conway's Game of Life 🎲

> A C++ implementation of Conway's Game of Life cellular automaton. This simulation demonstrates how complex patterns can emerge from simple rules, featuring both random grid generation and pattern file loading capabilities.

## Authors 👥

- For more information see my blog and my contributions to community.
    - [**dantsec**](https://www.github.com/dantsec)

## Documents 📂

- [**License**](./LICENSE)
- [**Patterns**](./patterns)

## Tech Stack 🧑‍💻

- This project was developed with the following technologies:
    - [**C++**](https://isocpp.org/) (Core implementation language)
    - [**Make**](https://www.gnu.org/software/make/) (Build system)
    - [**g++**](https://gcc.gnu.org/) (Compiler)

## Project Structure 🏗️

```sh
% cloc .
      26 text files.
      24 unique files.
       3 files ignored.

github.com/AlDanial/cloc v 1.98  T=0.28 s (85.2 files/s, 5195.1 lines/s)
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
C++                              7            159             19            524
Text                             7              0              0            140
Markdown                         1             47              0            139
C/C++ Header                     7             46            264             69
make                             1              6              6             31
INI                              1              2              0             11
-------------------------------------------------------------------------------
SUM:                            24            260            289            914
-------------------------------------------------------------------------------

% tree .
.
├── LICENSE
├── Makefile
├── README.md
├── patterns
│   ├── *.txt
└── src
    ├── include
    │   ├── args.hpp
    │   ├── constants.hpp
    │   ├── creator.hpp
    │   ├── files.hpp
    │   ├── grid.hpp
    │   ├── rule.hpp
    │   └── utils.hpp
    ├── lib
    │   ├── args.cpp
    │   ├── creator.cpp
    │   ├── files.cpp
    │   ├── grid.cpp
    │   ├── rule.cpp
    │   └── utils.cpp
    └── main.cpp

5 directories, 24 files
```

## Command Line Options 🛠️

```
Usage: ./main [OPTIONS]

Grid Configuration:
  -r, --rows <num>      Set the number of grid rows. Default: 20
  -c, --cols <num>      Set the number of grid columns. Default: 20
  -f, --file-path <string>      Load an initial grid pattern from a file instead of using a randomly generated grid.

Simulation Settings:
  -g, --gens <num>      Set the number of generations to simulate. Default: 5
  -p, --prob <num>      Set the probability (0–100) of a cell being alive at start. Default: 80%
  -m, --mode <num>      Set the simulation mode (0: Normal, 1: Interactive, 2: Movie, 3: Creator). Default: 0

General:
  -h, --help            Show this help message and exit.

Notes:
  > If no input file is provided with -f/--file-path, a grid will be randomly generated
    based on the specified rows, columns, and probability.
  > Probability only applies when generating a random grid (i.e., not using -f/--file-path).
```

## Installation / Run Locally ⚙️

- **Important**: Prerequisites - having [**g++ compiler**](https://gcc.gnu.org/) and [**Make**](https://www.gnu.org/software/make/) installed.

- Clone and enter the project directory:

```bash
git clone https://github.com/dantsec/cellular-automata.git && cd cellular-automata/
```

- Build the project:

```bash
make
```

- Run:

```bash
# Custom grid size and generations
./main -r 20 -c 30 -g 10 -p 50

# Load a pattern from file and simulate in movie mode
./main -r 20 -c 20 -g 50 -f patterns/glider.txt -m 2

# Entering in the creator mode
./main -m 3

# Show help
./main --help
```

- Clean project:

```bash
make clean
```

## The Game 👾

### Game Rules 📋

- The simulation follows Conway's original Game of Life rules:
    - **Birth**: A dead cell with exactly 3 live neighbors becomes alive;
    - **Survival**: A live cell with 2 or 3 live neighbors stays alive;
    - **Death**: A live cell with fewer than 2 neighbors dies (underpopulation);
    - **Death**: A live cell with more than 3 neighbors dies (overpopulation).

### Pattern Files 📁

- Pattern files use a simple format where:
    - `1` represents a live cell;
    - `0` represents a dead cell;
    - Cells are separated by spaces;
    - Each row is on a new line;
    - By default, it's a 20x20 grid.

- For example, **glider pattern**:

```
0 0 0 0 0
0 0 1 0 0
0 0 0 1 0
0 1 1 1 0
0 0 0 0 0
```

## To-Do 📌

- [ ] When saving, let the user decide whether he wants to save as a grid or as a coordinate;
- [ ] When you have a file as input, know how to identify whether it is a grid or coordinate file, and feed the grid from that.

## Contributing 🛠️

```bash
# Create a fork from the original repository and clone it.
git clone https://github.com/YOUR_USERNAME/GameOfLife.git

# Enter into the project folder.
cd GameOfLife/

# Create a new branch with the name feat-[BRANCH_NAME].
git checkout -b feat-[BRANCH_NAME]

# Make your changes and commit them.
git add . && git commit -m "feat(<scope>): YOUR_COMMIT_MESSAGE"

# Push your branch and open a pull request.
git push origin feat-[BRANCH_NAME]
```
