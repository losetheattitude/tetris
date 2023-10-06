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

        switch(keyPressed){
            case KEY_LEFT:
            game.MoveBlockLeft();
            break;

            case KEY_RIGHT:
            game.MoveBlockRight();
            break;

            case KEY_DOWN:
            game.MoveBlockDown();

            game.UpdateScore(0, 1);
            break;

            case KEY_UP:
            game.RotateBlock();
            break;
        }

        if(game.level->ShouldLevelUp()){
            game.level->AdjustLevel();
        }

        if(game.level->ShouldTick()){
            game.MoveBlockDown();
        }
    }
};