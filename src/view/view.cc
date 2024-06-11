#include "mwod/view/view.h"

void displayTime(uint8_t hours, uint8_t minutes, uint8_t seconds) {
    std::cout << unsigned(hours) << ":" << unsigned(minutes) << ":"
              << unsigned(seconds) << std::endl;
}
