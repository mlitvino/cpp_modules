#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <string>
#include <iostream>

class FragTrap : public virtual ClapTrap
{
	protected:
		static constexpr int	_default_hp = 100;
		static constexpr int	_default_energy = 100;
		static constexpr int	_default_attackDamage = 30;
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
