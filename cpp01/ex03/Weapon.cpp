#include "Weapon.hpp"

void	Weapon::setType(std::string	new_type)
{
	_type = new_type;
}

const std::string& Weapon::getType(void)
{
	return _type;
}

Weapon::Weapon(std::string new_type)
{
	setType(new_type);
}

Weapon::Weapon(void) {}
