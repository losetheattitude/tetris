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

    static void Init(Game& game);
    static CommandFactory* GetInstance();

    Command* MakeSingleton(CommandType type);
    ~CommandFactory();
};