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

bool isChar(std::string input)
{
    if (!isascii(input[0]) || input.length() > 1)
        return false;
    return true;
}

bool isInt(std::string input)
{
    const char *str = input.c_str();
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    for (; str[i]; i++)
    {
        if (!std::isdigit(input[i]))
            return false;
    }
    return true;
}

bool isFloat(std::string input)
{
    int last = input.length();
    bool has_point = false;
    bool has_digit = false;
    int i = 0;

    if (input == "nanf" || input == "+inff" || input == "-inff")
            return true;
    if (input[last - 1] != 'f' || last < 2)
        return false;
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (; i < last - 1; i++)
    {
        if (input[i] == '.')
        {
            if (has_point)
                return false;
            has_point = true;
            continue;
        }
        else if (std::isdigit(input[i]))
        {
            has_digit = true;
            continue;
        }
        else
            return false;
    }
    return has_point && has_digit;
}

bool isDouble(std::string input)
{
    int i = 0;
    bool has_point = false;
    bool has_digit = false;

        if (input == "nan" || input == "+inf" || input == "-inf")
            return true;
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (; input[i]; i++)
    {
        if (input[i] == '.')
        {
            if (has_point)
                return false;
            has_point = true;
            continue;
        }
        else if (std::isdigit(input[i]))
        {
            has_digit = true;
            continue;
        }
        else
            return false;
    }
    return has_point && has_digit;
}

void printChar(double input, bool isSpecial)
{
    if (isSpecial)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(input))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;
}

void printInt(double input, bool isSpecial)
{
    if (isSpecial)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(input) << std::endl;
}

void printFloat(double input)
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(input) << "f" << std::endl;
}

void printDouble(double input)
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << input << std::endl;
}

void ScalarConverter::convert(std::string input)
{
    double value = 0;
    bool isSpecial = false;

    if (isChar(input))
    {
        if (std::isprint(input[0]))
            value = static_cast<int>(input[0]);
        else
            std::cout << "Non displayable" << std::endl;
    }
    else if (isInt(input) || isFloat(input) || isDouble(input))
    {
        if (input == "nanf" || input == "+inff" || input == "-inff"
         || input == "nan" || input == "+inf" || input == "-inf")
            isSpecial = true;
        value = std::strtod(input.c_str(), NULL);
    }
    else
    {
        std::cout << "Error: enter a valid argument" << std::endl;
        return ;
    }

    printChar(value, isSpecial);
    printInt(value, isSpecial);
    printFloat(value);
    printDouble(value);
}