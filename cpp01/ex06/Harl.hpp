#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

# define MAX_LEVEL 4

enum level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl
{
	private:
		std::string levels[MAX_LEVEL];
		void (Harl::*levels_func[MAX_LEVEL])(void);
		enum level levels_enum;
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		int find_level(std::string& level);
	public:
		Harl();
		void complain(std::string level);
};

#endif
