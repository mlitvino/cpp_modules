#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap &obj);
		ScavTrap& operator= (const ScavTrap &obj);
		ScavTrap(const std::string name);
		void	attack(const std::string& target);
		void	guardGate();
};

#endif
