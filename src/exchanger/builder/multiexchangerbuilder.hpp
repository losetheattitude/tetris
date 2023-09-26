#pragma once

#include <vector>

#include "exchangerbuilder.hpp"
#include "../../storage/storage.hpp"

class MultiExchangerBuilder : public ExchangerBuilder
{
private:
    Storage* storages;

public:
    MultiExchangerBuilder(Storage* storages);
    Exchanger* Build() override;
};