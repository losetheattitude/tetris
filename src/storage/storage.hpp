#pragma once
#include <iostream>

enum class StorageType 
{
    LOCAL,
    AWS,
    GCP,
    FTP,
};

class Storage{
public:
    virtual std::string Read() = 0;
    virtual void Write(const std::string& payload) = 0;
};