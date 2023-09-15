#include <iostream>
#include "clock.hpp"

Clock::Clock()
{
    this->lastUpdateTime = 0;
}

bool Clock::HasPassed()
{ 
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }

    return false;
}

void Clock::SetInterval(double interval)
{
    this->interval = interval;
}

double Clock::GetInterval()
{
    return this->interval;
}