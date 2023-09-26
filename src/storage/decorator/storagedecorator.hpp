#pragma once

#include "../storage.hpp"

enum class DecoraterType 
{
    ENCRYPT,
    SIGN
};

class StorageDecorator : public Storage {
private:
    Storage* storage;

public:
    StorageDecorator(Storage* storage);

    virtual std::string Read() = 0;
    virtual void Write(const std::string& payload) = 0;
};