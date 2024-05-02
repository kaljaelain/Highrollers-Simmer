#ifndef GETFUNCS_H
#define GETFUNCS_H
#include <string>
#include <string_view>
using namespace std;

int getStats();
int getSims();
string getStatName();
int getMinRange(string_view statName);
int getMaxRange(string_view statName);
double getUserDefinitionRange(string_view sv);


#endif
