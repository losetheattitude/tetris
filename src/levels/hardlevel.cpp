#include "hardlevel.hpp"

HardLevel::HardLevel(Clock* clock):BaseLevel(clock){}

void HardLevel::Configure()
{
    level = 0;
    maxLevel = 99;
    speedUp = 0.005;
    this->clock->SetInterval(0.5);
    
    levelThreshHold = 400;
    levelText = "Hard";

    lineScores[0] = 200;
    lineScores[1] = 400;
    lineScores[2] = 600;
    lineScores[3] = 1000;
}