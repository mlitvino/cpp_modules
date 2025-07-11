#include "HumanA.hpp"

void	HumanA::attack(void)
{
	std::cout
	<< _name << " attacks with their " << _weapon.getType()
	<< std::endl;
};

HumanA::HumanA(const std::string name, Weapon& weapon)
	: _weapon{weapon}
{
	_name = name;
}

void	HumanA::setWeapon(Weapon& weapon)
{
	_weapon = weapon;
}
