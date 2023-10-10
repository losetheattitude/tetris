#pragma once

#include "../core/game.hpp"

enum class CommandType 
{
    NOOP = 0,
    DOWN = 1, 
    RIGHT = 2, 
    LEFT = 3, 
    RESET = 4,
    SWAP_STATE = 5,
    ROTATE = 6 
};

class Game;
class Command
{
protected:
    Game& game;

public:
    Command(Game& game);

    CommandType type;
    virtual void Execute() = 0;

    void Rotate();
    void Down();
    void Left();
    void Right();
    void Pause();
    void Play();
    void Reset();
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

