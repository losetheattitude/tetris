#pragma once

#include "exchangerbuilder.hpp"

class AwsExchangerBuilder : public ExchangerBuilder
{
public:
    AwsExchangerBuilder();
    Exchanger* Build();
};