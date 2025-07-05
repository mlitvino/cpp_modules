#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout
	<< _name << " attacks with their " << _weapon->getType()
	<< std::endl;
}

HumanB::HumanB(const std::string name)
{
	_name = name;
}
