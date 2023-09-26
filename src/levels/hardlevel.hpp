#pragma once

#include "level.hpp"
#include "../core/clock.hpp"

class HardLevel : public Level {
public:
    HardLevel(Clock* clock);
    void Configure() override;
};