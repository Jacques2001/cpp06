#include "Serializer.hpp"

int main()
{
    Data value(1);
    Serializer::serialize(&value);
    return 0;
}