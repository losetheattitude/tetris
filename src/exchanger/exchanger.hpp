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

    ExchangeableIdentity ExchangeToStorage(Exchangeable* exchangeable);
    Exchangeable* ExchangeFroStorage(const struct ExchangeableIdentity& definition);
};