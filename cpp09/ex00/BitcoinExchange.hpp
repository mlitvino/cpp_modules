
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>

#define STD_DATE_FORMAT "YYYY-MM-DD"
#define PATH_PRICE_DB "./data.csv"

#define MIN 0
#define MAX 1000

typedef std::chrono::year_month_day ymd_t;
typedef std::multimap<ymd_t, double> map_t;

class BitcoinExchange
{
	private:
		map_t	_priceDb;

		ymd_t	convertStrToDate(std::string& date);
		double	convertStrToValue(std::string& value);
		void	loadDataBase(map_t& db,std::string filename);
		double	findValue(ymd_t& str_date);
	public:
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		BitcoinExchange();
		void	exchange(std::string filename);

		class OptionalException : public std::exception
		{
			private:
				const char *msg;
			public:
				OptionalException(const char *arg) : msg{arg} {};
				const char* what() const noexcept override
				{
					return msg;
				}
		};
};

#endif
