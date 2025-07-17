#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <float.h>

class ScalarConverter
{
	public:
		virtual ~ScalarConverter() = 0;
		static void	convert(const std::string& str);
};

#endif

