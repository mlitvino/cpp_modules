
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <utility>
#include <ctime>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <iomanip>


#define STD_DATE_FORMAT "YYYY-MM-DD"
#define PATH_PRICE_DB "./test.csv"

class BitcoinExchange
{
	private:
		std::multimap<std::tm, double>	_priceDb;
		std::multimap<std::tm, double>	_amountDb;
		std::tm	convertStrToDate(std::string& date);
		double	convertStrToValue(std::string& value);
	public:
		BitcoinExchange();

		class InvalidFormat : public std::exception
		{
			public:
				const char* what() const noexcept override
				{
					return "format is invalid!";
				}
		};
};

#endif
