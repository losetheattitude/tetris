#pragma once

#include "storagedecorator.hpp"

class SignDecorator : public StorageDecorator
{
public:
    std::string Read();
    void Write(const std::string& payload);
};