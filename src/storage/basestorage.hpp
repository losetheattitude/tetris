#pragma once
#include <iostream>

enum StorageType 
{

};

class BaseStorage{
    std::string Read();
    void Write(std::string payload);
};