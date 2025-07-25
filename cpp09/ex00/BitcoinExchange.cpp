#include "BitcoinExchange.hpp"

std::tm	BitcoinExchange::convertStrToDate(std::string& date)
{
	static const std::string	fmt = STD_DATE_FORMAT;
	std::tm tm{};
	std::istringstream ss(date);

	if (fmt.length() != date.length())
		throw InvalidFormat();
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail())
		throw InvalidFormat();
	return tm;
}

double	BitcoinExchange::convertStrToValue(std::string& str_value)
{
	static const std::string	valid = "-+.0123456789";

	if (str_value.find_first_not_of(valid) != std::string::npos
		|| str_value.find_first_of("+") != str_value.find_last_of("+")
		|| str_value.find_first_of("-") != str_value.find_last_of("-")
		|| str_value.find_first_of(".") != str_value.find_last_of("."))
		throw InvalidFormat();
	return std::stod(str_value);
}

// Orthodox Canonical Form

BitcoinExchange::BitcoinExchange()
	: _priceDb{}
	, _amountDb{}
{
	std::ifstream	infile(PATH_PRICE_DB);
	std::string		input;

	if (!infile.good())
		throw std::runtime_error("std::ifstream failed to open price database");
	std::getline(infile, input);
	if (input != "date,exchange_rate")
		throw InvalidFormat();
	while (std::getline(infile, input))
	{
		std::cout << "DB: " << input << std::endl;
		if (input.find(",") == std::string::npos)
			throw InvalidFormat();
		std::string	str_date = input.substr(0, input.find(","));
		std::string	str_value = input.substr(input.find(",") + 1);
		std::tm	tm_date = convertStrToDate(str_date);
		double	value = convertStrToValue(str_value);
		_priceDb.emplace(tm_date, value);
		std::cout << str_date << " | " << std::fixed << std::setprecision(2) << value << std::endl;
	}
	if (infile.bad())
		throw std::runtime_error("getline failed to get line");
}

