#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hp;
		int			_energy;
		int			_attackDamage;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(const ClapTrap &obj);
		ClapTrap& operator= (const ClapTrap &obj);
		ClapTrap(const std::string name);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
