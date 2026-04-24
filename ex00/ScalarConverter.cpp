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

// void ScalarConverter::convert(std::string input) 
// {
//     double d = std::atof(input.c_str());

//     std::cout << "char : ";
//     if (input.length() == 1 && !isdigit(d))
//         std::cout << "'" << static_cast<char>(input[0]) << "'" << std::endl;
//     if (d < 0 || d > 127 || input == "nan" || input == "nanf" )
//         std::cout << "impossible" << std::endl;
//     else if (!isprint(static_cast<int>(d)))
//             std::cout << "Non displayable" << std::endl;
//     else
//         std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

//     std::cout << "int : ";

//     if (d > INT_MAX || d < INT_MIN || input == "nan" || input == "nanf")
//         std::cout << "impossible" << std::endl;
//     else
//         std::cout << static_cast<int>(d) << std::endl;
    
//     std::cout << std::fixed << std::setprecision(1);
//     std::cout << "float : ";
//     std::cout << static_cast<float>(d) << "f" << std::endl;
//     std::cout << "double : ";
//     std::cout << static_cast<double>(d) << std::endl;
// }

bool isChar(std::string input)
{
    if (!std::isalpha(input[0]) || input.length() > 1)
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

void ScalarConverter::convert(std::string input)
{
    if (isChar(input))
    {
        std::cout << "it's a char" << std::endl;
    }
    else if (isInt(input))
    {
        std::cout << "it's an int" << std::endl;
    }
    else if (isFloat(input))
    {
        std::cout << "it's a float" << std::endl;
    }
    else if (isDouble(input))
    {
        std::cout << "it's a double" << std::endl;
    }
    else
        std::cout << "Please, enter a valid argument" << std::endl;
}