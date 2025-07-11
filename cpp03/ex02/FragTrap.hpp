#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <string>
#include <iostream>

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(const FragTrap &obj);
		FragTrap& operator= (const FragTrap &obj);
		FragTrap(const std::string name);
		void	highFivesGuys(void);
		void	attack(const std::string& target);
};

#endif
