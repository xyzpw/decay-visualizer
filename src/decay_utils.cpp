#include <iostream>
#include <vector>
#include <utility>
#include <chrono>
#include "common.h"
#include "screen_manager.h"

std::vector<DecayItem> makeDecayItems(int count)
{
    std::vector<DecayItem> items{};
    auto termSize = getTerminalSize();

    for (int i = 0; i < count; ++i){
        double p = static_cast<double>(std::rand()) / RAND_MAX;
        std::pair<int, int> coord = getRandCoordinates(termSize);
        DecayItem dItem{.coordinates=coord, .decayThreshold=p};
        items.push_back(dItem);
    }

    return items;
}

double getCurrentEpoch()
{
    using namespace std::chrono;
    auto epochObj = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    double epoch = static_cast<double>(epochObj.count()) / 1000;
    return epoch;
}

// Remove chemicals from vector if they have reached their decay threshold.
void purgeDecayedItems(std::vector<DecayItem>& items, double pNotDecayed)
{
    for (auto it = items.begin(); it != items.end();)
    {
        if (it->decayThreshold >= pNotDecayed)
            items.erase(it);
        else
            ++it;
    }
}
