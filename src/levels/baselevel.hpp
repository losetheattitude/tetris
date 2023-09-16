
#pragma once
#include <cmath>
#include <iostream>

#include "../util/clock.hpp"

class BaseLevel{
protected:
    int level;
    int maxLevel;
    int* score;

    double speedUp;
    int levelThreshHold;

    std::string levelText;
    int lineScores[4];

private:
    int GetExpectedLevel();

public:
    Clock* clock;
    
    virtual void Configure() = 0;
    
    BaseLevel(Clock* clock);
    ~BaseLevel();

    int GetLineScore(int numLines);
    bool ShouldLevelUp();
    void SetScore(int* score);
    int GetLevel();
    std::string GetLevelText();
    bool ShouldTick();
    void AdjustLevel();
};