#include "BitcoinExchange.hpp"

class dum : public std::exception
{
	public:
		dum()
		{
			throw std::runtime_error("ahaha");
		};
};

int	main(int ac, char **av)
{
	// if (ac != 2)
	// {
	// 	std::cout << "Usage: ./BitcoinExchange <database_name>" << std::endl;
	// 	return 0;
	// }
	// try
	// {
	// 	BitcoinExchange	exec;

	// 	exec.loadAmountDb(av[1]);
	// }
	// catch(std::exception& e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	try
	{
		throw dum();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
