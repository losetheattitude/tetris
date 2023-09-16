#include "colors.hpp"

const Color darkGrey = {26, 31, 40, 255};
const Color tDarkGrey = {26, 31, 40, 80};

const Color green = {47, 230, 23, 255};
const Color tGreen = {47, 230, 23, 80};

const Color red = {232, 18, 18, 255};
const Color tRed = {232, 18, 18, 80};

const Color orange = {226, 116, 17, 255};
const Color tOrange = {226, 116, 17, 80};

const Color yellow = {237, 234, 4, 255};
const Color tYellow = {237, 234, 4, 80};

const Color purple = {166, 0, 247, 255};
const Color tPurple = {166, 0, 247, 80};

const Color cyan = {21, 204, 209, 255};
const Color tCyan = {21, 204, 209, 80};

const Color blue = {13, 64, 216, 255};
const Color tBlue = {13, 64, 216, 80};

const Color lightBlue = {59, 85, 162, 255};
const Color tLightBlue = {59, 85, 162, 80};

const Color darkBlue = {44, 44, 127, 255};
const Color tDarkBlue = {44, 44, 127, 80};

std::vector<Color> GetCellColors()
{
    return {
        darkGrey, 
        green,
        red, 
        orange, 
        yellow, 
        purple, 
        cyan, 
        blue,
    };
}

std::vector<Color> GetShadowColors()
{
    return {
        tDarkGrey,
        tGreen, 
        tRed,
        tOrange,
        tYellow,
        tPurple,
        tCyan,
        tBlue
    };
}