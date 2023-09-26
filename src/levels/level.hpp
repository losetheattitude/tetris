
#pragma once
#include <cmath>
#include <iostream>

#include "../core/clock.hpp"

class Level{
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
    
    Level(Clock* clock);
    ~Level();

    int GetLineScore(int numLines);
    bool ShouldLevelUp();
    void SetScore(int* score);
    int GetLevel();
    std::string GetLevelText();
    bool ShouldTick();
    void AdjustLevel();
};