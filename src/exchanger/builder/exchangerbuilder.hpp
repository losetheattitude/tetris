#pragma once

#include "../exchanger.hpp"
#include "../../levels/level.hpp"
#include "../../formatter/formatter.hpp"
#include "../../formatter/rawformat.hpp"
#include "../../storage/factory.hpp"
#include "../../formatter/factory.hpp"

class ExchangerBuilder{
private:
    Storage* storage;
    Formatter* formatter;

public:
    ExchangerBuilder();

    void Reset();

    ExchangerBuilder* UseEncryption();
    ExchangerBuilder* UseSignature();
    
    ExchangerBuilder* UseRaw();
    ExchangerBuilder* UseXML();
    ExchangerBuilder* UseJSON();

    virtual Exchanger* Build() = 0;
};