#pragma once

#include "../../commands/command.hpp"

class Terminal
{
public:
    virtual CommandType GetNext() = 0;
    void Reset();
};