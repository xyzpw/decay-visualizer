#pragma once

#include <iostream>
#include <utility>
#include <vector>

// Store decay info for a chemical.
struct DecayItem{
    const char* asciiChar = "\u232c";
    std::pair<int, int> coordinates; // Screen coordinates
    double decayThreshold; // Fraction below which the chemical decays
};

// Store decay info for the simulation.
struct DecayInfo{
    double ke;
};

void startDisplay(DecayInfo chemInfo, std::vector<DecayItem>& chemicals); // Implemented in "screen_manager.cpp"

// Implemented in "decay_utils.cpp"
std::vector<DecayItem> makeDecayItems(int count);
double getCurrentEpoch();
void purgeDecayedItems(std::vector<DecayItem>& items, double pNotDecayed);
