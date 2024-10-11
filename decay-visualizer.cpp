#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "screen_manager.h"
#include "input_handler.h"
#include "common.h"
#include "decay_formulas.h"

int main(int argc, char** argv)
{
    std::srand(std::time(0));
    setlocale(LC_ALL, "");

    int itemCount = prompt<int>("item display count: ");
    double halflife = prompt<double>("half-life (seconds): ");
    std::cout << std::endl;

    DecayInfo chemInfo{.ke=convertConstOrHalflife(halflife)};
    std::vector<DecayItem> chemicals = makeDecayItems(itemCount);

    startDisplay(chemInfo, chemicals);

    return 0;
}
