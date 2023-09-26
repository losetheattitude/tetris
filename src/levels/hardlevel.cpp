#include "hardlevel.hpp"

HardLevel::HardLevel(Clock* clock):Level(clock){}

void HardLevel::Configure()
{
    level = 0;
    maxLevel = 99;
    speedUp = 0.0045;
    this->clock->SetInterval(0.5);
    
    levelThreshHold = 1000;
    levelText = "Hard";

    lineScores[0] = 200;
    lineScores[1] = 400;
    lineScores[2] = 600;
    lineScores[3] = 1000;
}