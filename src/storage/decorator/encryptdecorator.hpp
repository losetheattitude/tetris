#pragma once

#include "storagedecorator.hpp"

class EncryptDecorator : public StorageDecorator 
{
public:
    std::string Read();
    void Write(const std::string& payload);
};