#include "joystick.hpp"

JoyStick::JoyStick(Terminal* terminal_): terminal(terminal_)
{
    this->factory = CommandFactory::GetInstance();
    //TODO: buffered storage for replay
}

JoyStick::~JoyStick()
{
    delete this->terminal;
}

Command* JoyStick::ProduceCommand() const
{
    return this->factory->MakeCommandSingleton(
        this->terminal->GetNext()
    );
}

