#include "printFuncs.h"
#include <string_view>
#include <iostream>

using namespace std;
void printIndividualHighRoll(string_view sv, int i, int roll, double highThreshold) {
	cout << sv << ": " << i + 1 << "---> " 
		 << roll << "---> High (>" << (highThreshold * 100) << "%)!\n";
}

void printIndividualMidroll(string_view sv, int i, int roll, double lowThreshold, double highThreshold) {
	cout << sv << ": " << i + 1 << "---> " 
		 << roll << "---> Mid (" << (lowThreshold * 100) << '-' << (highThreshold * 100) << "%)!\n";
}

void printIndividualLowroll(string_view sv, int i, int roll, double lowThreshold) {
	cout << sv << ": " << i + 1 << "---> " 
		 << roll << "---> Low (<" << (lowThreshold * 100) << "%)!\n";
}

void printIndividualRollSummary(int numSimulations, int highRollsInd, int midRollsInd, int lowRollsInd) {
	cout << '\n'
		 << "- - - - - -\n"
		 << "Out of " << numSimulations << " simulations, we got: \n"
		 << highRollsInd << " highrolled individual stats.\n"
		 << midRollsInd << " midrolled individual stats.\n"
		 << lowRollsInd << " lowrolled individual stats.\n"
		 << "- - - - - -\n"
		 << '\n';
}

void printRollCategoryDefinitions(double highThreshold, double lowThreshold, int numSimulations) {
	cout << '\n'
		 << "- - - - - -\n"
		 << "Items categorized by their complete rolls: \n"
		 << "- - - - - -\n"
		 << "High roll = Combined stats are above " << (highThreshold * 100) << "% of its potential.\n"
		 << "Useable roll = Combined stats are between " << (lowThreshold * 100) << "% and " << (highThreshold * 100) << "% of its potential.\n"
		 << "Meh roll = Combined stats are below " << (lowThreshold * 100) << "% of its potential.\n"
		 << "- - - - - -\n"
		 << '\n'
		 << "Out of " << numSimulations << " simulations, we got: \n";

}

void printTotalRollQualitysAndPercent(int highRoll, int useableRoll, int mehRoll, double rollsPerAttemptHigh, double rollsPerAttemptMid, double rollsPerAttemptLow) {
	cout << "- - - - - -\n"
		 << "High Rolls total: " << highRoll << "!\n"
		 << "which is equal to " << rollsPerAttemptHigh << "%" << '\n'
		 << "- - -\n"
		 << "Useable Rolls total: " << useableRoll << "!\n"
		 << "which is equal to " << rollsPerAttemptMid << "%" << '\n'
		 << "- - -\n"
		 << "Meh Rolls total: " << mehRoll << "!\n"
		 << "which is equal to " << rollsPerAttemptLow << "%" << '\n'
		 << "- - - - - -\n"
		 << '\n';
}

void printLineDivider() {
	cout << "***************\n"
		 << '\n';
}

void printRangeInputExplanation() {
	cout << '\n'
		<< "***********************\n"
		<< "Next, define at which N% you want items total stats to be categorized in.\n"
		<< "For example, if you want Highrolls to be the top 1 % of the items, enter 99\n"
		<< "Highrolls and Lowrolls will be categorized per your input - Midrolls will be categorized inbetween those values.\n"
		<< "************************\n"
		<< '\n';
}