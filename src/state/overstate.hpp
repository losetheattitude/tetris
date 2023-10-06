#pragma once

#include "./state.hpp"

class OverState : public State 
{
public:
    OverState()
    {
        identifier = GameState::OVER;
    }

    void HandleInput(Game& game, const int& keyPressed) override
    {
        if(keyPressed != KEY_R)
        {
            return;
        }

        game.Reset();
        game.state = makeStateSingleton(GameState::PLAY);
    }
};