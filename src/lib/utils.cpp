#include <cstdlib>
#include <iostream>
#include <string>

#include "../include/utils.hpp"

using namespace std;

void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

bool confirmWithDefault(string text, char defaultOption) {
    string input;

    cout << text;

    getline(cin, input);

    return (
        input.empty()
        || input[0] == tolower(defaultOption)
        || input[0] == toupper(defaultOption)
    );
}
