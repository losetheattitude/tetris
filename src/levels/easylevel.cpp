#include "easylevel.hpp"

void EasyLevel::Configure()
{
    level = 0;
    maxLevel = 99;
    speedUp = 0.005;
    this->clock->SetInterval(0.7);

    //each 1k levels up 1
    levelThreshHold = 2000;

    levelText = "Easy";
    lineScores[0] = 100;
    lineScores[1] = 300;
    lineScores[2] = 500;
    lineScores[3] = 700;
}