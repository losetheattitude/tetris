#include "factory.hpp"

Storage* makeStorage(StorageType type)
{
    switch(type)
    {
        case StorageType::LOCAL:
            return new LocalFileStorage();
    }
}