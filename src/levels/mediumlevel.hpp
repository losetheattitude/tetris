#pragma once

#include "baselevel.hpp"
#include "../util/clock.hpp"

class MediumLevel : public BaseLevel {
public:
    MediumLevel(Clock* clock);
    void Configure();
};