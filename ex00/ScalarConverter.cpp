#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}


int is_num(std::string value)
{
    for (int i = 0; value[i]; i++)
    {
        if (value[i] < '0' || value[i] > '9')
            return 0;  
    }
    return 1;
}

void ScalarConverter::convert(std::string value)
{
    if (value.length() == 1 && !isdigit(value[0]))
    {
        char c = value[0];
        int i = static_cast<int>(value[0]);
        float f = static_cast<float>(value[0]);
        double d = static_cast<double>(value[0]);
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << std::endl;
        std::cout << "double: " << d << std::endl;
    }

    if (is_num(value) == 1 && value.find_last_of("f") == 1)
        std::cout << "C'est un float" << std::endl;
    // if ()
}