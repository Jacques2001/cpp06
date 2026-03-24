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

int isChar(std::string input)
{
    const char *str = input.c_str();

    for (int i = 0; str[i]; i++)
    {
        if (!isalpha(str[i]))
            return 0;
    }
    return 1;
}

int isInt(std::string input)
{
    const char *str = input.c_str();

    for (int i = 0; str[i]; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}
int isFloat(std::string input)
{
    
    return 0;
}

int isDouble(std::string input)
{
    int last = input.length();
    if (input[last] != 'f')
        return 0;
    return 1;
}

void ScalarConverter::convert(std::string input)
{
    if (isChar(input))
        std::cout << "it's a char" << std::endl;
    else if (isInt(input))
        std::cout << "it's an int" << std::endl;
    else if (isFloat(input))
        std::cout << "it's a float" << std::endl;
    else if (isDouble(input))
        std::cout << "it's a double" << std::endl;
    else
        std::cout << "it's unknown" << std::endl;
}