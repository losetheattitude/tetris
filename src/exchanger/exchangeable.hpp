#pragma once

#include <map>
#include <string>

class Exchangeable 
{
public:
    virtual std::map<std::string, std::string>* Unform() = 0;
    virtual void Form(const std::map<std::string, std::string>& exchangables) = 0;
};