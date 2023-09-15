#pragma once
#include <raylib.h>
#include <iostream>

class Clock {
private:
    double interval;

public:
    double lastUpdateTime;
    
    Clock();
    bool HasPassed();
    void SetInterval(double interval);
    double GetInterval();
};