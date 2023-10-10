#pragma once

#include "../commands/factory.hpp"
#include "../core/game.hpp"

class Game;
class CommandFactory;

enum class GameState
{
    PAUSE = 0,
    PLAY = 1,
    OVER = 2
};

class State 
{
protected:
    CommandFactory* factory;
public:
    GameState identifier;
    virtual void ProcessCommand(Game& game, Command* command) = 0;
};