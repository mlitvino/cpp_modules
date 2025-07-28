#include "BitcoinExchange.hpp"

ymd_t	BitcoinExchange::convertStrToDate(std::string& date)
{
	static const std::string	fmt = STD_DATE_FORMAT;
	std::tm tm{};
	std::istringstream ss(date);

	if (fmt.length() != date.length())
		ThrowLine("format is invalid!");
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail())
		ThrowLine("format is invalid!");
	ymd_t	ymd
	{
		std::chrono::year{tm.tm_year + 1900} ,
		std::chrono::month{static_cast<unsigned>(tm.tm_mon + 1)} ,
		std::chrono::day{static_cast<unsigned>(tm.tm_mday)} ,
	};
	return ymd;
}

double	BitcoinExchange::convertStrToValue(std::string& str_value)
{
	static const std::string	valid = "-+.0123456789";

	if (str_value.find_first_not_of(valid) != std::string::npos
		|| str_value.find_first_of("+") != str_value.find_last_of("+")
		|| str_value.find_first_of("-") != str_value.find_last_of("-")
		|| str_value.find_first_of(".") != str_value.find_last_of("."))
		ThrowLine("format is invalid!");
	try
	{
		return std::stod(str_value);
	}
	catch(const std::exception& e)
	{
		return NAN;
	}
	return -1;
}

void	BitcoinExchange::loadDataBase(map_t& db,std::string filename, std::string delim, std::string format)
{
	std::ifstream	infile(filename);
	std::string		input;

	if (!infile.good())
		ThrowLine("std::ifstream failed to open a database");
	std::getline(infile, input);
	if (input != format)
		ThrowLine("format is invalid!");
	while (std::getline(infile, input))
	{
		std::cout << filename << " DB: " << input << std::endl;
		if (input.find(delim) == std::string::npos)
			ThrowLine("format is invalid!");
		std::string	str_date = input.substr(0, input.find(delim));
		std::string	str_value = input.substr(input.find(delim) + delim.length());
		ymd_t	tm_date = convertStrToDate(str_date);
		double	value = convertStrToValue(str_value);
		db.emplace(tm_date, value);
		std::cout << str_date << " | " << std::fixed << std::setprecision(2) << value << std::endl;
	}
	if (infile.bad())
		ThrowLine("getline failed to get line");
}

void	BitcoinExchange::loadAmountDb(std::string filename)
{
	loadDataBase(_amountDb, filename, " | ", "date | value");
}

// Orthodox Canonical Form

BitcoinExchange::BitcoinExchange()
	: _priceDb{}
	, _amountDb{}
{
	loadDataBase(_priceDb, PATH_PRICE_DB, ",", "date,exchange_rate");
}

