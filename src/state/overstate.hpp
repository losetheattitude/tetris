#pragma once

#include "./state.hpp"

class OverState : public State 
{
public:
    OverState()
    {
        identifier = GameState::OVER;
        factory = CommandFactory::GetInstance();
    }

    void ProcessCommand(Game& game, Command* command) override
    {
        if(command->type != CommandType::RESET){
            return;
        }

        command->Execute();
        this->factory->MakeCommandSingleton(CommandType::SWAP_STATE)
            ->Execute();
    }
};