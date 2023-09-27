#pragma once

#include <map>
#include <string>

enum class FormatType 
{
    RAW,
    XML,
    JSON
};

class Formatter
{
public:
    virtual void Form(const std::map<std::string, std::string>& data) = 0;
    virtual std::map<std::string, std::string> Unform(const std::string& payload) = 0;
};