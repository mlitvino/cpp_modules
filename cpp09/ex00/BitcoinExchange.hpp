
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
#define ThrowLine(arg) throw OptionalException(arg, __FILE__, __LINE__)

typedef std::chrono::year_month_day ymd_t;
typedef std::multimap<ymd_t, double> map_t;

class BitcoinExchange
{
	private:
		map_t	_priceDb;
		map_t	_amountDb;

		ymd_t	convertStrToDate(std::string& date);
		double	convertStrToValue(std::string& value);
		void	loadDataBase(map_t& db,std::string filename, std::string delim, std::string format);

	public:
		BitcoinExchange();
		void	loadAmountDb(std::string filename);

		class OptionalException : public std::exception
		{
			private:
				std::string	msg;
			public:
				OptionalException(const std::string& arg, const char *file, int line)
				{
					std::ostringstream	out;
					out << file << ": " << line << ": " << arg;
					msg = out.str();
				};
				~OptionalException() throw() {};
				const char* what() const noexcept override
				{
					return msg.c_str();
				}
		};
};

#endif
