#include "ScalarConverter.hpp"

static void printInvalid()
{
	std::cout
	<< "char: impossible\n"
	<< "int: impossible\n"
	<< "float: impossible\n"
	<< "double: impossible\n";
}

static void printTypes(const std::string& str, char ch, int in, float fl, double db)
{
	long double ld = std::stold(str);

	std::cout << "char: ";
	if (std::isnan(ld)
		|| ld < std::numeric_limits<char>::min()
		|| ld > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!isprint(ch))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << '\'' << ch << '\'' << std::endl;

	std::cout << "int: ";
	if (std::isnan(ld)
		|| ld < std::numeric_limits<int>::min()
		|| ld > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << in << std::endl;

	std::cout << std::fixed << std::setprecision(2);

	std::cout << "float: ";
	if (std::isfinite(ld)
		&& (ld < std::numeric_limits<double>::lowest()
		|| ld > std::numeric_limits<double>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << fl << 'f' << std::endl;

	std::cout << "double: ";
	if (std::isfinite(ld)
		&& (ld < std::numeric_limits<double>::lowest()
		|| ld > std::numeric_limits<double>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << db << std::endl;
}

static void convertStrToTypes(const std::string& str, int type)
{
	char	ch;
	int		in;
	float	fl;
	double	db;

	switch (type)
	{
		case CHAR_TYPE:
		{
			ch = str[1];
			in = static_cast<int>(ch);
			fl = static_cast<float>(ch);
			db = static_cast<double>(ch);
			return printTypes(str, ch, in, fl, db);
		}
		case INT_TYPE:
		{
			in = std::stoi(str);
			ch = static_cast<char>(in);
			fl = static_cast<float>(in);
			db = static_cast<double>(in);
			return printTypes(str, ch, in, fl, db);
		}
		case FLOAT_TYPE:
		{
			fl = std::stof(str);
			in = static_cast<int>(fl);
			ch = static_cast<char>(fl);
			db = static_cast<double>(fl);
			return printTypes(str, ch, in, fl, db);
		}
		case DOUBLE_TYPE:
		{
			db = std::stod(str);
			in = static_cast<int>(db);
			ch = static_cast<char>(db);
			fl = static_cast<float>(db);
			return printTypes(str, ch, in, fl, db);
		}
	}
}

static int	detectTYPE(const std::string& str)
{
	if (str.length() == 3 && str.front() == '\'' && str.back() == '\'')
	{
		return CHAR_TYPE;
	}

	if (str == "-inff" || str == "+inff" || str == "nanf")
		return FLOAT_TYPE;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return DOUBLE_TYPE;

	std::string specSymb = "+-f.";
	for (int i = 0, c; specSymb[i]; ++i)
	{
		c = 0;
		for (int j = 0; str[j]; ++j)
		{
			if (str[j] == specSymb[i])
				++c;
			if ((str[j] == 'f' && j != static_cast<int>(str.length() - 1))
				|| ((str[j] == '+' || str[j] == '-') && j != 0)
				|| (specSymb.find(str[j]) == std::string::npos && !isdigit(str[j])))
			{
				throw std::invalid_argument("Invalid literal");
			}
		}
		if (c > 1)
			throw std::invalid_argument("Invalid literal");
	}

	if (str.find('.') != std::string::npos && str.find('f') != std::string::npos)
	{
		std::stof(str);
		return FLOAT_TYPE;
	}
	else if (str.find('.') != std::string::npos)
	{
		std::stod(str);
		return DOUBLE_TYPE;
	}
	else
	{
		std::stoi(str);
		return INT_TYPE;
	}
	return -1;
}

void	ScalarConverter::convert(const std::string& str)
{
	try
	{
		int type = detectTYPE(str);
		convertStrToTypes(str, type);
	}
	catch (std::exception &e)
	{
		printInvalid();
	}
}


// Orthodox Canonical Form

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& other)
{
	if (this == &other)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

