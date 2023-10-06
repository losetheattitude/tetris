#include <iostream>

#include "level.hpp"
#include "easylevel.hpp"
#include "mediumlevel.hpp"
#include "hardlevel.hpp"
#include "../core/clock.hpp"

Level* instances[3]{
    new EasyLevel(),
    new MediumLevel(),
    new HardLevel()
};

Level* makeLevelSingleton(int degree)
{   
    return instances[degree];
}
