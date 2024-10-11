#include <iostream>
#include <cmath>

double computeRemainingFraction(double ke, double elapsed)
{
    double remainingFrac = std::exp(-ke * elapsed);
    return remainingFrac;
}

double convertConstOrHalflife(double value)
{
    double convertedValue = std::log(2) / value;
    return convertedValue;
}
