#include "ScavTrap.hpp"

void	ScavTrap::attack(const std::string& target)
{
	if (_energy <= 0)
		return ;
	--_energy;
	std::cout
	<< "ScavTrap: " << _name << " attacks " << target
	<< ", causing " << _attackDamage << " points pf damage!"
	<< std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap: " << _name << " is now in Gate keeper mode" << std::endl;
}

// Constructors + Destructor

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	_name = "nameless";
	_hp = _default_hp;
	_energy = _default_energy;
	_attackDamage = _default_attackDamage;
}

ScavTrap::ScavTrap(std::string name)
	: ScavTrap()
{
	std::cout << "ScavTrap: Arg constructor called" << std::endl;
	_name = name;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &obj)
{
	std::cout << "ScavTrap: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	_name = obj._name;
	_hp = obj._hp;
	_energy = obj._energy;
	_attackDamage = obj._attackDamage;
	return *this;
}
