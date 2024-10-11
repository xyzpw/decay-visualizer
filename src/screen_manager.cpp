#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>
#include <unistd.h>
#include <sys/ioctl.h>
#include <utility>
#include <algorithm>
#include "screen_manager.h"
#include "decay_formulas.h"
#include "common.h"

std::vector<int> QUIT_KEYS{static_cast<int>('q'), static_cast<int>('Q')};

std::string makeDisplayStatusString(double elapsed, int remaining);

void startDisplay(DecayInfo chemInfo, std::vector<DecayItem>& chemicals)
{
    double remainingFraction = 1;
    bool windowActive = true;

    auto haltIfQuitOrEliminated = [&](char c){
        int charDecimal = static_cast<int>(c);
        bool capturedKeyIsErr = c == ERR;
        bool hasQuit = false;
        if (!capturedKeyIsErr && std::find(QUIT_KEYS.begin(), QUIT_KEYS.end(), charDecimal) != QUIT_KEYS.end())
            hasQuit = true;
        bool isEliminated = chemicals.size() == 0;

        if (isEliminated || hasQuit)
            windowActive = false;
    };

    auto getCompletionMessage = [&](double elapsed){
        double halflivesPassed = elapsed / convertConstOrHalflife(chemInfo.ke);
        std::string result = std::string("completion time: ") + std::to_string(elapsed) + " s ";
        result += "(" + std::to_string(halflivesPassed) + " half-lives)";
        return result;
    };

    initscr();
    curs_set(0);
    use_default_colors();
    nodelay(stdscr, 1);

    double startingEpoch = getCurrentEpoch();
    while (windowActive)
    {
        erase();
        auto pressedKey = getch();
        double timeElapsed = getCurrentEpoch() - startingEpoch;
        remainingFraction = computeRemainingFraction(chemInfo.ke, timeElapsed);

        for (auto chem : chemicals)
            mvprintw(chem.coordinates.second, chem.coordinates.first, chem.asciiChar);
        mvprintw(0, 0, makeDisplayStatusString(timeElapsed, chemicals.size()).c_str());

        refresh();
        haltIfQuitOrEliminated(pressedKey);
        napms(50);
        purgeDecayedItems(chemicals, remainingFraction);
    }
    erase();
    endwin();

    double completionTime = getCurrentEpoch() - startingEpoch;
    std::cout << getCompletionMessage(completionTime) << "\n";
}

// Returns the number of columns and rows of the terminal, respectively.
std::pair<int, int> getTerminalSize()
{
    struct winsize wSize;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &wSize);
    std::pair<int, int> windowSize = std::make_pair(wSize.ws_col, wSize.ws_row);
    return windowSize;
}

// Returns a coordinate of column and row, respectively.
std::pair<int, int> getRandCoordinates(std::pair<int, int> termSize)
{
    int col = std::rand() % (termSize.first + 1);
    int row = std::rand() % (termSize.second + 1);
    std::pair<int, int> coordinates = std::make_pair(col, row);
    return coordinates;
}

std::string makeDisplayStatusString(double elapsed, int remaining)
{
    std::string elapsedString = std::to_string(elapsed);
    elapsedString = elapsedString.substr(0, elapsedString.find_last_of('.')+2);

    std::string result = std::string("elapsed: ") + elapsedString + " s\n";
    result += "remaining: " + std::to_string(remaining);
    return result;
}
