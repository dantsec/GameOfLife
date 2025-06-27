#include <cstdlib>

#include "../include/utils.hpp"

using namespace std;

void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
