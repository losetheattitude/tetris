#pragma once

#include "../../core/clock.hpp"
#include "terminal.hpp"

class LocalTerminal : public Terminal 
{
private:
    int activeKey;
    Clock clocks[3];

public:
    LocalTerminal();
    int GetActiveKey() override;
};