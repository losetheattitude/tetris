#include "joystick.hpp"

JoyStick::JoyStick(Terminal* terminal_): terminal(terminal_)
{
    this->factory = CommandFactory::GetInstance();
    //TODO: buffered storage for replay
    //Multi command and observer pattern to relay command execution
}

JoyStick::~JoyStick()
{
    delete this->terminal;
}

Command* JoyStick::ProduceCommand() const
{
    return this->factory->MakeSingleton(
           this->terminal->GetNext()
    );
}

