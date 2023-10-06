#pragma once

#include "./state.hpp"

class PlayState : public State 
{
public:
    PlayState()
    {
        identifier = GameState::PLAY;
    }

    void HandleInput(Game& game, const int& keyPressed) override
    {
        if(keyPressed == KEY_SPACE)
        {
            game.state = makeStateSingleton(GameState::PAUSE);
            return;
        }

        game.ProcessMove(keyPressed);
        if(game.level->ShouldLevelUp()){
            game.level->AdjustLevel();
        }

        if(game.level->ShouldTick()){
            game.MoveBlockDown();
        }
    }
};