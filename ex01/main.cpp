#include "Serializer.hpp"

int main()
{
    Data value(1);
    uintptr_t kewan = Serializer::serialize(&value);
    Data *n = Serializer::deserialize(kewan);
    if (&value == n)
        std::cout << "Same" << std::endl;
    std::cout << "original value address = " << &value << std::endl;
    std::cout << "kewan's address = " << kewan << std::endl;
    std::cout << "value after cast = " << n << std::endl;
    return 0;
}