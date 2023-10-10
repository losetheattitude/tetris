#pragma once

#include "command.hpp"

class Game;
enum class CommandType;

class CommandFactory 
{
private:
    Game* game;
    Command* commands[7];

protected:
    CommandFactory() = default;
    static CommandFactory* instance_;

public:
    CommandFactory(CommandFactory &other) = delete;
    void operator=(const CommandFactory &) = delete;

    Command* MakeCommandSingleton(CommandType type);

    static void Init(Game& game);
    static CommandFactory* GetInstance();
};