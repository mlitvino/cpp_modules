#include "ScavTrap.hpp"

void	ScavTrap::attack(const std::string& target)
{
	if (_energy <= 0)
		return ;
	--_energy;
	std::cout
	<< _name << " attacks " << target
	<< ", causing " << _attackDamage << " points pf damage!"
	<< std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << _name << " is now in Gate keeper mode" << std::endl;
}

// Constructors + Destructor

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	_name = "nameless";
	_hp = 100;
	_energy = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "ScavTrap: Arg constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
	: ClapTrap()
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
