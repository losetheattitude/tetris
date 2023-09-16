#pragma once
#include <raylib.h>
#include <vector>

extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightBlue;
extern const Color darkBlue;

extern const Color tDarkGrey;
extern const Color tGreen;
extern const Color tRed;
extern const Color tOrange;
extern const Color tYellow;
extern const Color tPurple;
extern const Color tCyan;
extern const Color tBlue;
extern const Color tLightBlue;
extern const Color tDarkBlue;

std::vector<Color> GetCellColors();
std::vector<Color> GetShadowColors();