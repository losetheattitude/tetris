#include "mediumlevel.hpp"

MediumLevel::MediumLevel(Clock* clock):Level(clock){}

void MediumLevel::Configure()
{
    level = 0;
    maxLevel = 99;
    speedUp = 0.005;
    this->clock->SetInterval(0.6);
    
    //each 1k levels up 1
    levelThreshHold = 1500;
    levelText = "Medium";

    lineScores[0] = 150;
    lineScores[1] = 350;
    lineScores[2] = 550;
    lineScores[3] = 800;
}