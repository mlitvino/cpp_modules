#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert <number>" << std::endl;
	}
	else
	{
		ScalarConverter::convert(av[1]);
	}
	return 0;
}
