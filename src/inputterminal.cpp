#include "inputterminal.hpp"
#include "./util/clock.hpp"

InputTerminal::InputTerminal()
{   
    //Down button
    this->clocks[0].SetInterval(0.03);

    //Right-Left button
    this->clocks[1].SetInterval(0.09);

    //Up button
    this->clocks[2].SetInterval(0.35);
}

int InputTerminal::GetActiveKey()
{       
    int pressedKey = GetKeyPressed();
    if(pressedKey != 0)
    {
        this->activeKey = pressedKey;
        if(this->activeKey == KEY_DOWN)
        {
            this->clocks[0].lastUpdateTime = GetTime();
        }
        else if(this->activeKey == KEY_LEFT || this->activeKey == KEY_RIGHT)
        {
            this->clocks[1].lastUpdateTime = GetTime();
        }
        else if(this->activeKey == KEY_UP)
        {
            this->clocks[2].lastUpdateTime = GetTime();
        }

        return this->activeKey;
    }

    if(this->activeKey != 0 && IsKeyReleased(this->activeKey))
    {
        this->activeKey = 0;

        return this->activeKey;
    }

    if(this->activeKey != 0 && !IsKeyReleased(this->activeKey))
    {
        if(this->activeKey == KEY_DOWN && this->clocks[0].HasPassed())
        {
            return this->activeKey;
        }
        else if((this->activeKey == KEY_LEFT || this->activeKey == KEY_RIGHT) && this->clocks[1].HasPassed())
        {
            return this->activeKey;
        }
        else if(this->activeKey == KEY_UP && this->clocks[2].HasPassed())
        {
            return this->activeKey;
        }
        else
        {
            return pressedKey;
        }
    }

    return pressedKey;
}