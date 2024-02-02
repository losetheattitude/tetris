#pragma once

#include "../../core/clock.hpp"
#include "terminal.hpp"

class LocalTerminal : public Terminal 
{
private:
    int activeKey;
    Clock clocks[3];

public:
    std::map<int, CommandType> keyMap{
        {0, CommandType::NOOP},
        {KEY_DOWN, CommandType::DOWN},
        {KEY_UP, CommandType::ROTATE},
        {KEY_LEFT, CommandType::LEFT},
        {KEY_RIGHT, CommandType::RIGHT},
        {KEY_R, CommandType::RESET},
        {KEY_SPACE, CommandType::SWAP_STATE}
    };
    
    LocalTerminal();
    int Capture();
    CommandType GetNext() override;
    
    void Reset();
};