#include "ScavTrap.hpp"

// Constructors + Deconstructor

ScavTrap::ScavTrap()
	: _hp{10}
	, _energy{10}
	, _attackDamage{0}
{
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	_name = "nameless";
}

// ScavTrap::ScavTrap(std::string name)
// 	: ScavTrap()
// {
// 	std::cout << "ScavTrap: Arg constructor called" << std::endl;
// 	_name = name;
// }

// ScavTrap::ScavTrap(const ScavTrap &obj)
// {
// 	std::cout << "ScavTrap: Copy constructor called" << std::endl;
// 	*this = obj;
// }

// ScavTrap::~ScavTrap()
// {
// 	std::cout << "ScavTrap: Deconstructor called" << std::endl;
// }

// ScavTrap& ScavTrap::operator= (const ScavTrap &obj)
// {
// 	std::cout << "ScavTrap: Copy assignment constructor called" << std::endl;
// 	if (this == &obj)
// 		return *this;
// 	_name = obj._name;
// 	_hp = obj._hp;
// 	_energy = obj._energy;
// 	_attackDamage = obj._attackDamage;
// 	return *this;
// }
