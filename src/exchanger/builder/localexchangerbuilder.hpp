#pragma once

#include "exchangerbuilder.hpp"

class LocalExchangerBuilder : public ExchangerBuilder 
{
public:
    LocalExchangerBuilder();
    // LocalExchangerBuilder();
    // LocalExchangerBuilder();

    Exchanger* Build();
};