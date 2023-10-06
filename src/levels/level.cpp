#include "level.hpp"

Level::Level()
{
    this->clock = new Clock();
}

Level::~Level()
{
    delete this->clock;
}

int Level::GetExpectedLevel()
{
    return (int)((*this->score / this->levelThreshHold) + 0.5);
}


int Level::GetLineScore(int numLines)
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

bool Level::ShouldLevelUp()
{
    return this->GetExpectedLevel() > this->level;
}

void Level::SetScore(int* score)
{
    this->score = score;
}

int Level::GetLevel()
{
    return this->level + 1;
}

std::string Level::GetLevelText()
{
    return this->levelText;
}

bool Level::ShouldTick()
{
    return this->clock->HasPassed();
}

void Level::AdjustLevel()
{
    double currentInterval = this->clock->GetInterval();
    while(this->level != this->GetExpectedLevel() && this->level < this->maxLevel){
        this->level++;
        currentInterval -= this->speedUp;
    }

    this->clock->SetInterval(currentInterval);
}
