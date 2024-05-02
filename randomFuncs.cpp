#include "randomFuncs.h"
#include <cstdlib>
#include <ctime>

int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}