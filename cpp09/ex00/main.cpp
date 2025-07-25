#include "BitcoinExchange.hpp"

#include <ctime>
#include <iostream>
#include <string>
#include <sstream>


#include <chrono>


int	main(int ac, char **av)
{
	try
	{
		BitcoinExchange	exec;

	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
