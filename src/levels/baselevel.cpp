#include "baselevel.hpp"

BaseLevel::BaseLevel(Clock* clock)
{
    this->clock = clock;
}

BaseLevel::~BaseLevel()
{
    delete this->clock;
}

int BaseLevel::GetExpectedLevel()
{
    return (int)((*this->score / this->levelThreshHold) + 0.5);
}


int BaseLevel::GetLineScore(int numLines)
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

bool BaseLevel::ShouldLevelUp()
{
    return this->GetExpectedLevel() > this->level;
}

void BaseLevel::SetScore(int* score)
{
    this->score = score;
}

int BaseLevel::GetLevel()
{
    return this->level + 1;
}

std::string BaseLevel::GetLevelText()
{
    return this->levelText;
}

bool BaseLevel::ShouldTick()
{
    return this->clock->HasPassed();
}

void BaseLevel::AdjustLevel()
{
    double currentInterval = this->clock->GetInterval();
    while(this->level != this->GetExpectedLevel() && this->level < this->maxLevel){
        this->level++;
        currentInterval -= this->speedUp;
    }

    this->clock->SetInterval(currentInterval);
}
