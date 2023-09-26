#pragma once

#include "level.hpp"
#include "../core/clock.hpp"

class EasyLevel : public Level {
public:
    EasyLevel(Clock* clock);
    void Configure() override;
};