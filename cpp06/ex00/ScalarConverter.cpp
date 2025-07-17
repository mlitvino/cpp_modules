#include "ScalarConverter.hpp"

enum
{
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	UNKNOWN
};

static void printUnknown()
{
	std::cout
	<< "char: impossible\n"
	<< "int: impossible\n"
	<< "float: impossible\n"
	<< "double: impossible\n"
	<< std::endl;
}

static char convertToChar(const std::string& str)
{
	return str.at(1);
}

static int convertToInt(const std::string& str)
{

}

static float convertToFloat(const std::string& str)
{

}

static double convertToDouble(const std::string& str)
{

}

void	convertToOther(auto value, int type)
{

}

static long double converStrToType(const std::string& str, int type)
{
	switch (type)
	{
		case CHAR_TYPE:
		{
			char w;
			convertToOther(w, type);
			return convertToChar(str);
		}
		case INT_TYPE:
			return convertToInt(str);
		case FLOAT_TYPE:
			return convertToFloat(str);
		case DOUBLE_TYPE:
			return convertToDouble(str);
	}
}

static int	detectTYPE(const std::string& str)
{
	if (str.length() == 3 && str.front() == '\'' && str.back() == '\'')
	{
		return CHAR_TYPE;
	}
	else if (str == "-inff" || str == "+inff" || str == "nanf" ||
			(str.find_first_of('.') == str.find_last_of('.') && str.find_last_of('.') != std::string::npos
			&& str.find_first_of('f') == str.find_last_of('f') && str.back() == 'f'))
	{
		return FLOAT_TYPE;
	}
	else if (str == "-inf" || str == "+inf" || str == "nan" ||
			(str.find_first_of('.') == str.find_last_of('.') && str.find_last_of('.') != std::string::npos))
	{
		return DOUBLE_TYPE;
	}
	for (char c : str)
	{
		if (!isdigit(c))
			return UNKNOWN;
	}
	return INT_TYPE;
}

void	ScalarConverter::convert(const std::string& str)
{
	std::cout << str << std::endl;
	std::cout << "------" << std::endl;

	double x = 4545654546546545456464546445624542654645.14546465145645646416;

	int type = detectTYPE(str);
	if (type == UNKNOWN)
	{
		printUnknown();
		return ;
	}
	long double value = converStrToType(str, type);
	// convertToOther(value, type);
}
