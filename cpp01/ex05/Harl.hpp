#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

# define MAX_LEVEL 4

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		std::string levels[MAX_LEVEL];
		void (Harl::*levels_func[MAX_LEVEL])(void);
	public:
		Harl();
		void complain(std::string level);
};

#endif
