#include "factory.hpp"

CommandFactory* CommandFactory::instance_;

void CommandFactory::Init(Game& game)
{
    if(CommandFactory::instance_ != nullptr){
        return;
    }

    CommandFactory::instance_ = new CommandFactory();
    CommandFactory::instance_->game = &game;

    CommandFactory::instance_->commands[0] = new NoOpCommand(game);
    CommandFactory::instance_->commands[1] = new DownCommand(game);
    CommandFactory::instance_->commands[2] = new RightCommand(game);
    CommandFactory::instance_->commands[3] = new LeftCommand(game);
    CommandFactory::instance_->commands[4] = new ResetCommand(game);
    CommandFactory::instance_->commands[5] = new SwapStateCommand(game);
    CommandFactory::instance_->commands[6] = new RotateCommand(game);
    CommandFactory::instance_->commands[7] = new TickCommand(game);
}

CommandFactory* CommandFactory::GetInstance()
{
    return CommandFactory::instance_;
}

Command* CommandFactory::MakeSingleton(CommandType type)
{
    return CommandFactory::instance_->commands[static_cast<int>(type)];
}

CommandFactory::~CommandFactory()
{
    delete commands[0];
}