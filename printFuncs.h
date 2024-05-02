#ifndef PRINTFUNCS_H
#define PRINTFUNCS_H

#include <string_view>
using namespace std;

void printIndividualHighRoll(string_view sv, int i, int roll, double highThreshold);
void printIndividualMidroll(string_view sv, int i, int roll, double lowThreshold, double highThreshold);
void printIndividualLowroll(string_view sv, int i, int roll, double lowThreshold);
void printIndividualRollSummary(int numSimulations, int highRollsInd, int midRollsInd, int lowRollsInd);
void printRollCategoryDefinitions(double highThreshold, double lowThreshold, int numSimulations);
void printTotalRollQualitysAndPercent(int highRoll, int useableRoll, int mehRoll, double rollsPerAttemptHigh, double rollsPerAttemptMid, double rollsPerAttemptLow);
void printLineDivider();
void printRangeInputExplanation();

#endif // !PRINTFUNCS_H

