#include "exchangerbuilder.hpp"

ExchangerBuilder::ExchangerBuilder()
{
    this->Reset();
}

// Exchanger* ExchangerBuilder::Build(const int& flags)
// {
//     BaseStorage* storage;
//     if(flags & (int)StorageType::LOCAL)
//     {
//         storage = makeStorage(StorageType::LOCAL);
//     }
//     else if(flags & (int)StorageType::REMOTE)
//     {
//         storage = makeStorage(StorageType::REMOTE);
//     }

//     BaseTransformer* formatter;
//     if(flags & (int)FormatType::RAW)
//     {
//         formatter = new RawTransformer();
//     }

//     return new Exchanger(storage, formatter);
// }

void ExchangerBuilder::Reset()
{
    this->storage = nullptr;
    this->formatter = nullptr;
}

// ExchangerBuilder* ExchangerBuilder::UseLocal()
// {
//     this->storage = makeStorage(StorageType::LOCAL);

//     return this;
// }

// ExchangerBuilder* ExchangerBuilder::UseRemote()
// {
//     this->storage = makeStorage(StorageType::REMOTE);

//     return this;
// }

// ExchangerBuilder* ExchangerBuilder::UseRaw()
// {   
//     if(formatter == nullptr)
//     {

//     }

//     BaseTransformer* transformer = makeTransformer(FormatType::RAW);
//     // this->transformers.push_back(transformer);

//     return this;
// }

// ExchangerBuilder* ExchangerBuilder::UseXML()
// {
//     BaseTransformer* transformer = makeTransformer(FormatType::XML);
//     // this->transformers.push_back(transformer);

//     return this;
// }

// ExchangerBuilder* ExchangerBuilder::UseJSON()
// {
//     BaseTransformer* transformer = makeTransformer(FormatType::JSON);
//     // this->transformers.push_back(transformer);

//     return this;
// }

// ExchangerBuilder* ExchangerBuilder::UseEncryption()
// {
//     BaseTransformer* transformer = makeTransformer(FormatType::ENCRYPTED);
//     // this->transformers.push_back(transformer);

//     return this;
// }

// ExchangerBuilder* ExchangerBuilder::UseSignature()
// {
//     BaseTransformer* transformer = makeTransformer(FormatType::SIGNED);
//     // this->transformers.push_back(transformer);

//     return this;
// }