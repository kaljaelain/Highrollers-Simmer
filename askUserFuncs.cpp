#include "askUserFuncs.h"
#include "validateInput.h"
#include <iostream>
#include <cctype>
#include <sstream>

using namespace std;

char askUserToViewIndividualRolls() {
    ostringstream prompt;
    prompt  << "One more thing before simulation, do you wish to view all the individual rolls?\n" << "Enter 'y' for yes or 'n' for no: ";

    return getInput<char>(prompt.str());
}

bool viewIndividualRolls(char i) {
    char lowerCaseInput = tolower(i);
    bool choice{ i == 'y' ? true : false };

    return choice;
}

char askToStart() {
    ostringstream prompt;
    prompt << "Do you wish to simulate again? (y/n) ";

    return getInput<char>(prompt.str());
}