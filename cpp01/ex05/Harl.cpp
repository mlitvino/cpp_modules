#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout
	<< "[ DEBUG ]\n"
	<< "I love having extra bacon\n"
	<< "for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
	<< "I really do!\n"
	<< std::endl;
}

void	Harl::info(void)
{
	std::cout
	<< "[ INFO ]\n"
	<< "I cannot believe adding extra bacon costs more money.\n"
	<< "You didn't put enough bacon in my burger!\n"
	<< "If you did, I wouldn't be asking for more!\n"
	<< std::endl;
}

void	Harl::warning(void)
{
	std::cout
	<< "[ WARNING ]\n"
	<< "I think I deserve to have some extra bacon for free.\n"
	<< "I've been coming for years whereas you started working here since last month.\n"
	<< std::endl;
}

void	Harl::error(void)
{
	std::cout
	<< "[ ERROR ]\n"
	<< "This is unacceptable! I want to speak to the manager now.\n"
	<< std::endl;
}

Harl::Harl(void)
	: levels{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	}
	, levels_func{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	}
{ }

void	Harl::complain(std::string level)
{
	for(int i = 0; i < MAX_LEVEL; i++)
	{
		if (levels[i] == level)
		{
			(this->*levels_func[i])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]\n";
}
