#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
		return 0;
	try
	{
		PmergeMe	exec;

		exec.getInput(&av[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
