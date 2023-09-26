#include "storagedecorator.hpp"

StorageDecorator::StorageDecorator(Storage* storage)
{
    this->storage = storage;
}