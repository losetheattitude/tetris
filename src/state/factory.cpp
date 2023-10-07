#include "factory.hpp"
#include "playstate.hpp"
#include "pausestate.hpp"
#include "overstate.hpp"

State* states[3]{
    new PauseState(), 
    new PlayState(), 
    new OverState()
};

State *makeStateSingleton(GameState state)
{
    return states[static_cast<int>(state)];
}