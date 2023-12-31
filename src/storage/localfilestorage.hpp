#pragma once

#include "storage.hpp"

class LocalFileStorage : public Storage 
{
public:
    LocalFileStorage();

    std::string Read();
    void Write(const std::string& payload);
};