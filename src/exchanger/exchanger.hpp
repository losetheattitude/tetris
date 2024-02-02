#pragma once

#include "./exchangeable.hpp"
#include "../storage/storage.hpp"
#include "../formatter/formatter.hpp"

class Exchanger {
private:
    Storage* storage;
    Formatter* formatter;

public:

    Exchanger(Storage* storage, Formatter* formatter);
    ~Exchanger();

    IExchangeable::Identity ExchangeToStorage(IExchangeable* exchangeable);
    IExchangeable* ExchangeFroStorage(const struct IExchangeable::Identity& definition);
};