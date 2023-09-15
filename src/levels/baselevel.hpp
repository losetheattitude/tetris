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
    int GetExpectedLevel()
    {
        return (int)((*this->score / this->levelThreshHold) + 0.5);
    }

    void AdjustTick()
    {
        double newInterval = this->clock->GetInterval() - this->speedUp;
        this->clock->SetInterval(newInterval);
    }

    void LevelUp()
    {
        int expectedLevel = this->GetExpectedLevel();
        
        this->AdjustTick();
        this->level++;
    }

public:
    Clock* clock;
    virtual void Configure() = 0;

    BaseLevel(Clock* clock)
    {
        this->clock = clock;
    }

    int GetLineScore(int numLines)
    {
        switch(numLines){
            case 0:
                return 0;
            case 1:
                return this->lineScores[0];
            case 2:
                return this->lineScores[1];
            case 3:
                return this->lineScores[2];
            default:
                return this->lineScores[3];
        }

        return 0;
    }

    bool ShouldLevelUp()
    {
        return this->GetExpectedLevel() > this->level;

    }

    void SetScore(int* score)
    {
        this->score = score;
    }

    int GetLevel()
    {
        return this->level + 1;
    }

    std::string GetLevelText()
    {
        return this->levelText;
    }

    bool ShouldTick()
    {
        return this->clock->HasPassed();
    }

    void AdjustLevel()
    {
        double currentInterval = this->clock->GetInterval();
        while(this->level != this->GetExpectedLevel() && this->level < this->maxLevel){
            this->level++;
            currentInterval = currentInterval - this->speedUp;
        }

        this->clock->SetInterval(currentInterval);
    }
};