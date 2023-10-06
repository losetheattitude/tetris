#pragma once

#include "./state.hpp"

extern State* states[3];
State *makeStateSingleton(GameState state);