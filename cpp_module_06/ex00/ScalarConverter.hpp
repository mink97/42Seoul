#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <ctype.h>

class ScalarConverter
{
	private:

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& ref);
		~ScalarConverter();
		ScalarConverter&	operator=(const ScalarConverter& ref);

		static void convert(const std::string& argv);
};

#endif
