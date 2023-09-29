#pragma once

#include <map>
#include <string>

enum class FormatType 
{
    RAW,
    XML,
    JSON
};

struct UnformedData 
{
    std::map<std::string, std::string> data;
};

struct FormedData
{
    std::string data;
};

class Formatter
{
public:
    virtual FormedData Form(const UnformedData& data) = 0;
    virtual UnformedData Unform(const FormedData& data) = 0;
};