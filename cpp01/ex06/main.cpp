#include "Harl.hpp"

int	main(void)
{
	std::string	input;
	Harl		Harl;

	while(1)
	{
		std::cout << "Type level for Harl: ";
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cout << "\n";
			break ;
		}
		Harl.complain(input);
	}
	return 0;
}
