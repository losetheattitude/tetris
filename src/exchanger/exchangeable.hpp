#pragma once

#include <map>
#include <string>

struct ExchangeableIdentity
{
    std::string id;
};

class Exchangeable 
{
public:
    virtual std::map<std::string, std::string>* Decompose() = 0;
    virtual void Compose(const std::map<std::string, std::string>& exchangables) = 0;
}; 