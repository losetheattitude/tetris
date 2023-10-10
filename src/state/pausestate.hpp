#pragma once

#include "state.hpp"

class PauseState : public State
{
public:
    PauseState()
    {
        identifier = GameState::PAUSE;
        factory = CommandFactory::GetInstance();
    }

    void ProcessCommand(Game& game, Command* command) override
    {
        if(command->type != CommandType::SWAP_STATE){
            return;
        }

        command->Execute();
    }
};