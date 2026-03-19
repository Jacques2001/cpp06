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

void ScalarConverter::convert(std::string input) 
{
    double d = std::atof(input.c_str());

    std::cout << "char : ";
    // if (input.length() == 1 && !isdigit(d))
    //     std::cout << "'" << static_cast<char>(input[0]) << "'" << std::endl;
    if (d < 0 || d > 127 || input == "nan" || input == "nanf" )
        std::cout << "impossible" << std::endl;
    else if (!isprint(static_cast<int>(d)))
            std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    std::cout << "int : ";
    // if (input.length() == 1 && !isdigit(d))
    //     std::cout << static_cast<int>(input[0]) << std::endl;
    if (d > INT_MAX || d < INT_MIN || input == "nan" || input == "nanf")
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float : ";
    // if (input.length() == 1 && !isdigit(d))
    //     std::cout << static_cast<float>(input[0]) << std::endl;
    // else
    std::cout << static_cast<float>(d) << "f" << std::endl;

    std::cout << "double : ";
    // if (input.length() == 1 && !isdigit(d))
    //     std::cout << static_cast<double>(input[0]) << std::endl;
    // else 
    std::cout << static_cast<double>(d) << std::endl;
}