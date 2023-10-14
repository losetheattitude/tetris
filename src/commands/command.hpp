#pragma once

#include <map>
#include <string>

#include "../core/game.hpp"
#include "../exchanger/exchangeable.hpp"

enum class CommandType 
{
    NOOP = 0,
    DOWN = 1, 
    RIGHT = 2, 
    LEFT = 3, 
    RESET = 4,
    SWAP_STATE = 5,
    ROTATE = 6,
    TICK = 7
};

class Game;
class Level;

class Command : public Exchangeable
{
protected:
    Game& game;

public:
    Command(Game& game);

    CommandType type;
    virtual void Execute() = 0;

    std::map<std::string, std::string>* Decompose()
    {
        return new std::map<std::string, std::string>();
    }

    void Compose(const std::map<std::string, std::string>& exchangables) 
    {

    }

    void Rotate();
    void Down(bool update = true);
    void Left();
    void Right();
    void Pause();
    void Play();
    void Reset();
    Level* GetLevel();
};

class RotateCommand : public Command
{
public:
    RotateCommand(Game& game);
    void Execute() override;
};

class DownCommand : public Command
{
public:
    DownCommand(Game& game);
    void Execute() override;
};

class RightCommand : public Command
{
public:
    RightCommand(Game& game);
    void Execute() override;
};

class LeftCommand : public Command
{
public:
    LeftCommand(Game& game);
    void Execute() override;
};

class SwapStateCommand : public Command
{
public:
    SwapStateCommand(Game& game);
    void Execute() override;
};

class ResetCommand : public Command
{
public:
    ResetCommand(Game& game);
    void Execute() override;
};

class NoOpCommand : public Command 
{
public:
    NoOpCommand(Game& game);
    void Execute() override;
};

class TickCommand : public Command
{
public:
    TickCommand(Game& game);
    void Execute() override;
};

class LevelUpCommand: public Command
{
public:
    LevelUpCommand(Game& game);
    void Execute() override;
};