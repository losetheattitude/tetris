#pragma once

#include "state.hpp"

class PauseState : public State
{
public:
    PauseState()
    {
        identifier = GameState::PAUSE;
    }

    void HandleInput(Game& game, const int& keyPressed) override
    {
        if(keyPressed != KEY_SPACE)
        {
            return;
        }

        game.state = makeStateSingleton(GameState::PLAY);
    }
};