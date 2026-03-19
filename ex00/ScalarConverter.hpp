#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <string>

class ScalarConverter
{
    private :
        ScalarConverter();
        ~ScalarConverter();

    public :
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        static void convert(std::string value);
};

#endif