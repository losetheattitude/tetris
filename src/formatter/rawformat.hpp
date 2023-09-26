#pragma once

#include "formatter.hpp"

class RawFormat : public Formatter
{
public:
    RawFormat();
    void form(const std::map<std::string, std::string>& data);
    std::map<std::string, std::string> unform(const std::string& payload);
};