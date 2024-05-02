#include "getFuncs.h"
#include "validateInput.h"
#include <sstream>
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

int getStats() {
    ostringstream prompt;
    int numStats{};
    prompt << "Enter the amount of stats for the item you wish to simulate: ";

    return getInput<int>(prompt.str());
}

int getSims() {
    ostringstream prompt;
    prompt << "And how many simulations do you wish to run? ";

    return getInput<int>(prompt.str());
}

string getStatName() {
    cout << "Enter name of the stat: ";
    string statName{};
    getline(cin >> ws, statName);
    return statName;
}

int getMinRange(string_view statName) {
    ostringstream prompt;
    prompt << "Enter the MINIMUM value of range for " << statName << ": ";

    return getInput<int>(prompt.str());
}
int getMaxRange(string_view statName) {
    ostringstream prompt;
    prompt << "Enter the MAXIMUM value of range for " << statName << ": ";

    return getInput<int>(prompt.str());
}

double getUserDefinitionRange(string_view sv) {
    ostringstream prompt;
    prompt << "Enter the num% at which item is categorized " << sv << ": ";

    return getInput<double>(prompt.str());
}
