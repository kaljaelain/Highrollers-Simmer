#include "askUserFuncs.h"
#include "getFuncs.h"
#include "printFuncs.h"
#include "randomFuncs.h"
#include "validateInput.h"
#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

using namespace std; // I know this is not recommended to use, but I still chose to use it due to it making std:: stuff simpler to use :)

int main() {
    #pragma region Get RNG seed & init vector statRanges
    srand(time(nullptr));
    vector<pair<string, pair<int, int>>> statRanges; //Note to self: Learn vectors well, seems V E R Y useful
    #pragma endregion

    char goAgain{}; //early init for "do while" loop
    do {

        int numStats{};
        int numSimulations{};

        do {
            numStats = { getStats() };
            if (numStats <= 0) {
                cout << "[INVALID INPUT] There must be atleast 1 stat to simulate.\n";
            }
        } while (numStats <= 0);

        do {
            numSimulations = { getSims() };
            if (numSimulations <= 0) {
                cout << "[INVALID INPUT] There must be atleast 1 simulation run.\n";
            }
        } while (numSimulations <= 0);

        #pragma region Initialize stats and store them to vector statRanges       
        int minRange{};
        int maxRange{};

        for (int i = 0; i < numStats; ++i) { //Get stats for each stat (as many as user entered) and store them to vector statRanges
            string statName{ getStatName() };
            int minRange{ getMinRange(statName) };

            while (minRange <= 0) { //input guard
                cout << "[INVALID INPUT] Minimum range needs to be atleast 1.\n";
                minRange = { getMinRange(statName) };
            }

            int maxRange{ getMaxRange(statName) };
            while (maxRange <= 0 || maxRange <= minRange) { //input guard
                cout << "[INVALID INPUT] Maximum range needs to be higher value than MINIMUM.\n";
                maxRange = { getMaxRange(statName) };
            }
            statRanges.push_back({ statName, {minRange, maxRange} }); //push the stats to vector "statRanges"
        }

        #pragma endregion

        
        printRangeInputExplanation();   //print the explanation for the following input request

        #pragma region Get Threshold values and guard the input
        double highThreshold{};   //early init so do while can see them
        double lowThreshold{};    //early init so do while can see them

        //Guarded get for low and high Thresholds
        do {
            lowThreshold = { (getUserDefinitionRange("LOWROLL") / 100) };
            if (lowThreshold <= 0) {
                cout << "[INVALID INPUT] Thresholds can not be zero or negative values.\n";
            }
        } while (lowThreshold <= 0);

        do {
            highThreshold = { (getUserDefinitionRange("HIGHROLL") / 100) };
            if (highThreshold <= lowThreshold) {
                cout << "[INVALID INPUT] High Threshold must be greater value than Low Threshold.\n";
            }
            else if (highThreshold <= 0) {
                cout << "[INVALID INPUT] Thresholds can not be zero or negative values.\n";
            }
        } while (highThreshold <= lowThreshold || highThreshold <= 0);
        #pragma endregion

        #pragma region Define some variables that are used later
        int highRollsInd{}; //to store amount for individual rolls
        int midRollsInd{};  //to store amount for individual rolls
        int lowRollsInd{};  //to store amount for individual rolls

        int totalStats{};       //to store amount of total stats (stat + stat = total)
        int totalPotential{};   //to store the potential max value of the item
        int highRoll{};         //to store quality of totalStats
        int useableRoll{};      //to store quality of totalStats
        int mehRoll{};          //to store quality of totalStats

        int roll{};             //temp variable for the loop
        #pragma endregion

        #pragma region Ask the user if we want to view individual stat rolls or not
        bool viewIndRolls{ viewIndividualRolls(askUserToViewIndividualRolls()) };
        #pragma endregion

        #pragma region Simulation 
        cout << "Now simulating " << numSimulations << " times...\n";

        for (int sim = 0; sim < numSimulations; ++sim) { //This is the simulator that runs as many times as the user gave it as input
            if (viewIndRolls != false) {
                cout << "**** Roll " << sim + 1 << " ****\n";
            }

            for (int i = 0; i < numStats; ++i) {        //This is the stat roller
                string statName = statRanges[i].first;
                int minRange = statRanges[i].second.first;
                int maxRange = statRanges[i].second.second;
                roll = { generateRandomNumber(minRange, maxRange) };
                if (roll >= (static_cast<double>(maxRange) * highThreshold)) { //Check if stat is top N% of its range
                    highRollsInd += 1;
                    if (viewIndRolls != false) {
                        printIndividualHighRoll(statName, i, roll, highThreshold);
                    }
                }
                else if (roll >= (static_cast<double>(maxRange) * lowThreshold) && roll < (static_cast<double>(maxRange) * highThreshold)) { //Check if stat is mid high% and low%
                    midRollsInd += 1;
                    if (viewIndRolls != false) {
                        printIndividualMidroll(statName, i, roll, lowThreshold, highThreshold);
                    }
                }
                else if (roll < (static_cast<double>(maxRange) * lowThreshold)) { //Check if stat is below low%
                    lowRollsInd += 1;
                    if (viewIndRolls != false) {
                        printIndividualLowroll(statName, i, roll, lowThreshold);
                    }
                }
                totalStats += roll;
                totalPotential += maxRange;
            }
            if (viewIndRolls != false) {
                printLineDivider();
            }
            double totalStatsDouble{ static_cast<double>(totalStats) };
            double totalPotentialDouble{ static_cast<double>(totalPotential) };

            if (totalStatsDouble > (totalPotentialDouble * highThreshold)) {
                highRoll += 1;
            }
            else if (totalStatsDouble < (totalPotentialDouble * highThreshold) && totalStats >(totalPotentialDouble * lowThreshold)) {
                useableRoll += 1;
            }
            else if (totalStatsDouble < (totalPotentialDouble * lowThreshold)) {
                mehRoll += 1;
            }
            totalStats = 0;
            totalPotential = 0;
        }
        #pragma endregion

        #pragma region Outputs
        if (viewIndRolls != false) {
            printIndividualRollSummary(numSimulations, highRollsInd, midRollsInd, lowRollsInd);
        }

        double rollsPerAttemptHigh{ (static_cast<double>(highRoll) / static_cast<double>(numSimulations)) * 100 };
        double rollsPerAttemptMid{ (static_cast<double>(useableRoll) / static_cast<double>(numSimulations)) * 100 };
        double rollsPerAttemptLow{ (static_cast<double>(mehRoll) / static_cast<double>(numSimulations)) * 100 };

        printRollCategoryDefinitions(highThreshold, lowThreshold, numSimulations);

        printTotalRollQualitysAndPercent(highRoll, useableRoll, mehRoll, rollsPerAttemptHigh, rollsPerAttemptMid, rollsPerAttemptLow);
        #pragma endregion

        #pragma region ask user to go again
        goAgain = { askToStart() };
        #pragma endregion
    } while (goAgain == 'y');
    return 0;
}