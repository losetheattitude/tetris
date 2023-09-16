#include <iostream>

#include "baselevel.hpp"
#include "easylevel.hpp"
#include "mediumlevel.hpp"
#include "hardlevel.hpp"
#include "../util/clock.hpp"

BaseLevel* instances[3];
BaseLevel* makeLevel(int degree)
{   
    if(instances[degree] != 0)
    {
        return instances[degree];
    }

    Clock* clock = new Clock();
    switch(degree)
    {
        case 0:
            instances[degree] = new EasyLevel(clock);
        case 1:
            instances[degree] = new MediumLevel(clock);
        case 2:
            instances[degree] = new HardLevel(clock);
        default:
            break;
    }

    return instances[degree];
}
