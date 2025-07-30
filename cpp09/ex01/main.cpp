#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RPN <expression>" << std::endl;
		return 0;
	}
	try
	{
		RPN	exec;

		exec.fillIn(av[1]);
	}
	catch(std::exception& e)
	{
		std::cerr << "Fatal Exception: " << e.what() << std::endl;
	}
	return 0;
}
