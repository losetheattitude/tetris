#pragma once

#include "formatter.hpp"

class RawFormat : public Formatter
{
public:
    RawFormat();
    std::string Form(const std::map<std::string, std::string>& data);
    std::map<std::string, std::string> Unform(const std::string& payload);
};