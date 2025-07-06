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

int	Harl::find_level(std::string& level)
{
	for(int i = 0; i < MAX_LEVEL; i++)
	{
		if (levels[i] == level)
			return i;
	}
	return -1;
}

void	Harl::complain(std::string level)
{
	int	level_i = find_level(level);
	switch(level_i)
	{
		case DEBUG:
			(this->*levels_func[level_i++])();
			[[fallthrough]];
		case INFO:
			(this->*levels_func[level_i++])();
			[[fallthrough]];
		case WARNING:
			(this->*levels_func[level_i++])();
			[[fallthrough]];
		case ERROR:
			(this->*levels_func[level_i])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
