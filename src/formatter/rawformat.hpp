#pragma once

#include "formatter.hpp"

class RawFormat : public Formatter
{
public:
    RawFormat();
    FormedData Form(const UnformedData& data);
    UnformedData Unform(const FormedData& data);
};