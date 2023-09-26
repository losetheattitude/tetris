#pragma once

#include "level.hpp"
#include "../core/clock.hpp"

class MediumLevel : public Level {
public:
    MediumLevel(Clock* clock);
    void Configure() override;
};