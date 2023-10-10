#pragma once

#include "./state.hpp"

class PlayState : public State 
{
public:
    PlayState()
    {
        identifier = GameState::PLAY;
        factory = CommandFactory::GetInstance();
    }

    void ProcessCommand(Game& game, Command* command) override
    {
        command->Execute();
        if(command->type == CommandType::SWAP_STATE) {
            return;
        }
        
        if(game.level->ShouldLevelUp()){
            game.level->AdjustLevel();
        }

        if(game.level->ShouldTick()){
            game.MoveBlockDown();
        }
    }
};