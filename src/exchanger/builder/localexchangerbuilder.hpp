#pragma once

#include "exchangerbuilder.hpp"

class LocalExchangerBuilder : public ExchangerBuilder 
{
public:
    Exchanger* Build() override;
};