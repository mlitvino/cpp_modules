#include "ClapTrap.hpp"

void	ClapTrap::attack(const std::string& target)
{
	if (_energy <= 0 || _hp <= 0)
		return ;
	--_energy;
	std::cout
	<< "ClapTrap: " << _name << " attacks " << target
	<< ", causing " << _attackDamage << " points pf damage!"
	<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << _name << " takes " << amount << " points of damages ";
	if (_hp <= 0)
	{
		std::cout << ", but he's already dead!" << std::endl;
	}
	else
	{
		_hp -= amount;
		std::cout << (_hp > 0 ? "and still alive!" : "and dies!") << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy <= 0 || _hp <= 0)
		return ;
	--_energy;
	_hp += amount;
	std::cout
	<< _name << " repairs itself "
	<< ", healing " << amount << " points of damage!"
	<< std::endl;
}

// Constructors + Destructor

ClapTrap::ClapTrap()
	: _hp{_default_hp}
	, _energy{_default_energy}
	, _attackDamage{_default_attackDamage}
{
	std::cout << "ClapTrap: Default constructor called" << std::endl;
	_name = "nameless";
}

ClapTrap::ClapTrap(std::string name)
	: ClapTrap()
{
	std::cout << "ClapTrap: Arg constructor called" << std::endl;
	_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "ClapTrap: Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &obj)
{
	std::cout << "ClapTrap: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	_name = obj._name;
	_hp = obj._hp;
	_energy = obj._energy;
	_attackDamage = obj._attackDamage;
	return *this;
}
