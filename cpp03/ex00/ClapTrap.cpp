#include "ClapTrap.hpp"

void	ClapTrap::attack(const std::string& target)
{
	if (_energy <= 0)
		return ;
	--_energy;
	std::cout
	<< _name << " attacks " << target
	<< ", causing " << _attackDamage << " points pf damage!"
	<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hp -= amount;
	std::cout
	<< _name << " takes " << amount << " points of damages "
	<< (_hp > 0 ? "and still alive!" : "and dies!")
	<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy <= 0)
		return ;
	--_energy;
	_hp += amount;
	std::cout
	<< _name << " repairs itself "
	<< ", healing " << amount << " points pf damage!"
	<< std::endl;
}

// Constructors + Destructor

ClapTrap::ClapTrap()
	: _hp{10}
	, _energy{10}
	, _attackDamage{0}
{
	std::cout << "Default constructor called" << std::endl;
	_name = "nameless";
}

ClapTrap::ClapTrap(std::string name)
	: ClapTrap()
{
	std::cout << "Arg constructor called" << std::endl;
	_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &obj)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	_name = obj._name;
	_hp = obj._hp;
	_energy = obj._energy;
	_attackDamage = obj._attackDamage;
	return *this;
}
