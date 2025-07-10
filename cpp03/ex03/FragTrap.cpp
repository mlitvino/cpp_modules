#include "FragTrap.hpp"

void	FragTrap::attack(const std::string& target)
{
	if (_energy <= 0)
		return ;
	--_energy;
	std::cout
	<< _name << " attacks " << target
	<< ", causing " << _attackDamage << " points pf damage!"
	<< std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: give me high five!" << std::endl;
}

// Constructors + Destructor

FragTrap::FragTrap()
{
	std::cout << "FragTrap: Default constructor called" << std::endl;
	_name = "nameless";
	_hp = 100;
	_energy = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "FragTrap: Arg constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj)
	: ClapTrap()
{
	std::cout << "FragTrap: Copy constructor called" << std::endl;
	*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called" << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap &obj)
{
	std::cout << "FragTrap: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	_name = obj._name;
	_hp = obj._hp;
	_energy = obj._energy;
	_attackDamage = obj._attackDamage;
	return *this;
}
