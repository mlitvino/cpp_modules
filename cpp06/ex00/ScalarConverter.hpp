#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

enum
{
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	INVALID
};

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator= (const ScalarConverter& other);
		virtual ~ScalarConverter() = 0;

		static void	convert(const std::string& str);

};

#endif

