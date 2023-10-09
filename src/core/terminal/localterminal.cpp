#include "localterminal.hpp"

LocalTerminal::LocalTerminal()
{   
    //Down button
    this->clocks[0].SetInterval(0.032);

    //Right-Left button
    this->clocks[1].SetInterval(0.1);

    //Up button
    this->clocks[2].SetInterval(0.5);
}

int LocalTerminal::GetActiveKey()
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