#include <vector>
#include <array>
#include <iostream>
#include "easyfind.hpp"

int	main()
{
	std::array<int, 8> cont{1, 2, 3, 4, 456, -854, 0, 0};
	//std::vector<int> cont{456, -854, 0, 0};

	int	toFind = -854;

	size_t i = easyfind(cont, toFind);

	std::cout
	<< "ToFind: " << toFind << "\n"
	<< "easyFind returns i: " << i << "\n";
	if (i < cont.size())
		std::cout << "Container[i]: " << cont[i] << std::endl;
	else
		std::cout << "Container : toFind not found" << std::endl;


	toFind = 99999;

	i = easyfind(cont, toFind);

	std::cout
	<< "ToFind: " << toFind << "\n"
	<< "easyFind returns i: " << i << "\n";
	if (i < cont.size())
		std::cout << "Container[i]: " << cont[i] << std::endl;
	else
		std::cout << "Container : toFind not found" << std::endl;


	return 0;
}


