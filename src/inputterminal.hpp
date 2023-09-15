#pragma once
#include <iostream>

#include <raylib.h>
#include "./util/clock.hpp"

class InputTerminal {
private:
    int activeKey;
    Clock clocks[3];

public:
    InputTerminal();
    int GetActiveKey();
};