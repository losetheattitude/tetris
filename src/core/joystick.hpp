#pragma once

#include <optional>

#include "game.hpp"
#include "terminal/terminal.hpp"
#include "../commands/command.hpp"

class JoyStick 
{
private:
    Terminal* terminal;
    CommandFactory* factory;

public:
    JoyStick(Terminal* terminal);
    ~JoyStick();

    Command* ProduceCommand() const;
};