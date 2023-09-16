#pragma once

#include "baselevel.hpp"
#include "../util/clock.hpp"

class EasyLevel : public BaseLevel {
public:
    EasyLevel(Clock* clock);
    void Configure();
};