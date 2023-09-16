#pragma once

#include "baselevel.hpp"
#include "../util/clock.hpp"

class HardLevel : public BaseLevel {
public:
    HardLevel(Clock* clock);
    void Configure();
};