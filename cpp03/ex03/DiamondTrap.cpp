#include "DiamondTrap.hpp"

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout
	<< "My name is " << _name
	<< "! My base ClapTrap's name is " << ClapTrap::_name
	<< std::endl;
}

// Constructors + Destructor

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
	_name = "nameless";
	_hp = FragTrap::_hp;
	_energy = ScavTrap::_energy;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
	: DiamondTrap()
{
	_name = name;
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "DiamondTrap: Arg constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj)
	: DiamondTrap()
{
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
	*this = obj;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap &obj)
{
	std::cout << "DiamondTrap: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	_name = obj._name;
	_hp = obj._hp;
	_energy = obj._energy;
	_attackDamage = obj._attackDamage;
	return *this;
}
