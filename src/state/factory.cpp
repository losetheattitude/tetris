#include "factory.hpp"
#include "playstate.hpp"
#include "pausestate.hpp"
#include "overstate.hpp"


State* states[3];
State* makeStateSingleton(GameState state)
{
    int index = static_cast<int>(state);
    if(states[index] != 0)
    {
        return states[index];
    }

    switch(state)
    {
        case GameState::PLAY:
        return states[index] = new PlayState();
        
        case GameState::PAUSE:
        return states[index] = new PauseState();
        
        case GameState::OVER:
        return states[index] = new OverState();
    }
}