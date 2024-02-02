#pragma once

#include <map>
#include <string>


class IExchangeable 
{
public:
    struct Identity
    {
        std::string id;
    };

    virtual std::map<std::string, std::string>* Decompose() = 0;
    virtual void Compose(const std::map<std::string, std::string>& exchangables) = 0;
};