#pragma once

#include <iostream>
#include <utility>

//NOTE: `startDisplay` is declared in "common.h" and defined in "screen_manager.cpp"

std::pair<int, int> getTerminalSize();
std::pair<int, int> getRandCoordinates(std::pair<int, int> termSize);
