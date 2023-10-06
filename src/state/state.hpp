#pragma once

#include "../core/game.hpp"

class Game;

enum class GameState
{
    PAUSE = 0,
    PLAY = 1,
    OVER = 2
};

class State 
{
public:
    GameState identifier;
    virtual void HandleInput(Game& game, const int& keyPressed) = 0;
};