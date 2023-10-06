#pragma once

#include "exchangerbuilder.hpp"

class LocalExchangerBuilder : public ExchangerBuilder 
{
public:
    // LocalExchangerBuilder();
    Exchanger* Build() override;
};