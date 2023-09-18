#pragma once

#include "game.hpp"
#include "storage/basestorage.hpp"
#include "transformer/basetransformer.hpp"

class Exchanger {
private:
    BaseStorage* storage;
    BaseTransformer* transformer;

public:
    Exchanger(BaseStorage* storage, BaseTransformer* transformer);

    std::string ExchangeToStorage(Game* game);
    Game* ExchangeFroStorage(std::string);
};