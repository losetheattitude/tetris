#pragma once

#include <map>
#include <string>

struct SaveData
{
    int grid[20][10];
    int level;
    int score;
    std::string difficulty;
};

enum class FormatType 
{
    RAW,
    XML,
    JSON
};

class Formatter
{
public:
    virtual void form(const std::map<std::string, std::string>& data) = 0;
    virtual std::map<std::string, std::string> unform(const std::string& payload) = 0;
};