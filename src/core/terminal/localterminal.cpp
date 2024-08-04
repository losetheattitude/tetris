#include "localterminal.hpp"

LocalTerminal::LocalTerminal()
{   
    //Down button
    this->clocks[0].SetInterval(/**0.032**/0.0019999);

    //Right-Left button
    this->clocks[1].SetInterval(0.09);

    //Up button
    this->clocks[2].SetInterval(0.4);
}

int LocalTerminal::Capture()
{       
    int pressedKey = GetKeyPressed();
    double pressedAt = GetTime();

    if(pressedKey != KEY_NULL)
    {
        this->activeKey = pressedKey;
        if(this->activeKey == KEY_DOWN)
        {
            this->clocks[0].lastUpdateTime = pressedAt;
        }
        else if(this->activeKey == KEY_LEFT || this->activeKey == KEY_RIGHT)
        {
            this->clocks[1].lastUpdateTime = pressedAt;
        }
        else if(this->activeKey == KEY_UP)
        {
            this->clocks[2].lastUpdateTime = pressedAt;
        }
 
        return this->activeKey;
    }

    if(this->activeKey != KEY_NULL && !IsKeyReleased(this->activeKey))
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
    }

    if(this->activeKey != KEY_NULL && IsKeyReleased(this->activeKey))
    {
        this->activeKey = KEY_NULL;

        return this->activeKey;
    }


    return pressedKey;
}

CommandType LocalTerminal::GetNext() 
{
    return this->keyMap[this->Capture()];
}

void LocalTerminal::Reset()
{
    this->activeKey = 0;
}