#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <string>
#include <iostream>

class ScavTrap : public virtual ClapTrap
{
	protected:
		static constexpr int	_default_hp = 100;
		static constexpr int	_default_energy = 50;
		static constexpr int	_default_attackDamage = 20;
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
