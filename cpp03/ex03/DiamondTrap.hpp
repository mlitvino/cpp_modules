#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
		int			_hp;
		int			_energy;
		int			_attackDamage;
	public:
		DiamondTrap();
		DiamondTrap(const std::string name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &obj);
		DiamondTrap& operator= (const DiamondTrap &obj);
		void	attack(const std::string& target);
		void	whoAmI();
};

#endif
