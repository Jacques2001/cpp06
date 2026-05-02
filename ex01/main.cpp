#include "Serializer.hpp"

int main()
{
    Data value(1);
    uintptr_t intptr = Serializer::serialize(&value);
    Data *n = Serializer::deserialize(intptr);
    if (&value == n)
        std::cout << "Same" << std::endl;
    std::cout << "original value address = " << &value << std::endl;
    std::cout << "intptr's address = " << intptr << std::endl;
    std::cout << "value after cast = " << n << std::endl;
    return 0;
}