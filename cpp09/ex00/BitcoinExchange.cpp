#include "BitcoinExchange.hpp"

Ymd	BitcoinExchange::convertStrToDate(std::string& date)
{
	static const std::string	fmt = STD_DATE_FORMAT;
	std::tm tm{};
	std::istringstream ss(date);

	if (fmt.length() != date.length())
		throw std::runtime_error("bad date");
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail())
		throw std::runtime_error("bad date");
	Ymd	ymd
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
		throw std::runtime_error("bad value");
	return std::stod(str_value);
}

void	BitcoinExchange::loadDataBase(PriceMap& db,std::string filename)
{
	std::ifstream	infile(filename);
	std::string		input;
	std::string		delim = ",";

	if (!infile.good())
		throw std::runtime_error("std::ifstream failed to open a database");
	std::getline(infile, input);
	if (input != "date,exchange_rate")
		throw std::runtime_error("format is invalid");
	while (std::getline(infile, input))
	{
		try
		{
			if (input.find(delim) == std::string::npos)
				throw std::runtime_error("format is invalid");
			std::string	str_date = input.substr(0, input.find(delim));
			std::string	str_value = input.substr(input.find(delim) + delim.length());
			Ymd	tm_date = convertStrToDate(str_date);
			double	value = convertStrToValue(str_value);
			db.emplace(tm_date, value);
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << ": " << input << std::endl;
		}
	}
	if (infile.bad())
		throw std::runtime_error("getline failed to get line");
}

double	BitcoinExchange::findValue(Ymd& tm_date)
{
	for (auto it = _priceDb.end(), begin = _priceDb.begin();;)
	{
		--it;
		if (!(it->first > tm_date))
			return it->second;
		if (it == begin)
			break;
	}
	throw std::runtime_error("no valid date in database");
	return -1;
}

static std::string formatDouble(double value)
{
	std::ostringstream	oss;
	oss << std::fixed << std::setprecision(10) << value;
	std::string s = oss.str();
	s.erase(s.find_last_not_of('0') + 1, std::string::npos);
	if (!s.empty() && s.back() == '.')
		s.pop_back();
	return s;
}

void	BitcoinExchange::exchange(std::string filename)
{
	std::ifstream	infile(filename);
	std::string		input;
	std::string		delim = " | ";

	if (!infile.good())
		throw std::runtime_error("std::ifstream failed to open a database");
	std::getline(infile, input);
	if (input != "date | value")
		throw std::runtime_error("format is invalid");
	while (std::getline(infile, input))
	{
		try
		{
			if (input.find(delim) == std::string::npos)
				throw std::runtime_error("format is invalid");
			std::string	str_date = input.substr(0, input.find(delim));
			std::string	str_value = input.substr(input.find(delim) + delim.length());
			Ymd	input_date = convertStrToDate(str_date);
			double	input_value = convertStrToValue(str_value);
			if (input_value < MIN || input_value > MAX)
				throw std::runtime_error("value out of range");
			double	db_value = findValue(input_date);
			double res = input_value * db_value;
			std::cout
			<< str_date << " => " << formatDouble(input_value) << " = " << formatDouble(res)
			<< std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << "Error: " << e.what() << ": " << input << std::endl;
		}
	}
	if (infile.bad())
		throw std::runtime_error("getline failed to get line");
}

// Orthodox Canonical Form

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _priceDb{other._priceDb}
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return *this;
	_priceDb = other._priceDb;
	return *this;
}

BitcoinExchange::BitcoinExchange()
	: _priceDb{}
{
	loadDataBase(_priceDb, PATH_PRICE_DB);
}

