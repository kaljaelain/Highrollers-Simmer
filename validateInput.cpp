#include "validateInput.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

template<typename T>
T getInput(const string& prompt) {
    T value;
    bool isValid = false;

    do {
        if (!prompt.empty()) {
            cout << prompt;
        }

        if (!(cin >> value)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[WARNING] Invalid input: \n";
        }
        else {
            isValid = true;
        }
    } while (!isValid);

    return value;
}
template int getInput<int>(const string&);
template double getInput<double>(const string&);
template string getInput<string>(const string&);
template char getInput<char>(const string&);