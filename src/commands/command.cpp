#include "command.hpp"

Command::Command(Game& game): game(game)
{

}

Level* Command::GetLevel()
{
    return this->game.level;
}

void Command::Rotate()
{
    this->game.RotateBlock();
}

void Command::Down(bool update)
{
    this->game.MoveBlockDown();

    if(update){
        this->game.UpdateScore(0, 1);
    }
}

void Command::Left()
{
    this->game.MoveBlockLeft();
}

void Command::Right()
{
    this->game.MoveBlockRight();
}

void Command::Play()
{
    this->game.state = makeStateSingleton(GameState::PLAY);
}

void Command::Pause()
{
    this->game.state = makeStateSingleton(GameState::PAUSE);
}

void Command::Reset()
{
    this->game.Reset();
}


RotateCommand::RotateCommand(Game& game): Command(game)
{
    this->type = CommandType::ROTATE;
}

void RotateCommand::Execute()
{
    this->Rotate();
}

DownCommand::DownCommand(Game& game): Command(game)
{
    this->type = CommandType::DOWN;
}

void DownCommand::Execute()
{
    this->Down();
}

RightCommand::RightCommand(Game& game): Command(game)
{
    this->type = CommandType::RIGHT;
}

void RightCommand::Execute()
{
    this->Right();
}

LeftCommand::LeftCommand(Game& game): Command(game)
{
    this->type = CommandType::LEFT;
}

void LeftCommand::Execute()
{
    this->Left();
}

SwapStateCommand::SwapStateCommand(Game& game): Command(game)
{
    this->type = CommandType::SWAP_STATE;
}

void SwapStateCommand::Execute()
{
    if(this->game.isPlayState())
    {
        this->Pause();
    }
    else
    {
        this->Play();
    }
}

ResetCommand::ResetCommand(Game& game): Command(game)
{
    this->type = CommandType::RESET;
}

void ResetCommand::Execute()
{
    this->Reset();
}


NoOpCommand::NoOpCommand(Game& game): Command(game)
{
    this->type = CommandType::NOOP;
}

void NoOpCommand::Execute()
{

}

TickCommand::TickCommand(Game& game): Command(game)
{
    this->type = CommandType::TICK;
}

void TickCommand::Execute()
{
    // auto level = this->GetLevel();
    
    this->Down(false);
}