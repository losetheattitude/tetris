#pragma once
#include "level.hpp"

extern Level* instances[3];
Level* makeLevelSingleton(int degree);
