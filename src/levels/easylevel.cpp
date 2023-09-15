#include "baselevel.hpp"
#include "../util/clock.hpp"

class EasyLevel : public BaseLevel {
public:
    EasyLevel(Clock* clock) : BaseLevel(clock){};

    void Configure()
    {
        level = 0;
        maxLevel = 99;
        speedUp = 0.005;
        this->clock->SetInterval(0.7);

        //each 1k levels up 1
        levelThreshHold = 1000;

        levelText = "Easy";
        lineScores[0] = 100;
        lineScores[1] = 300;
        lineScores[2] = 500;
        lineScores[3] = 700;
    }
};