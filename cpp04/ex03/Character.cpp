#include "Character.hpp"

std::string const& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		if (!_inv[i])
		{
			_inv[i] = m;
			std::cout << _name << ": I equipped the AMateria" << std::endl;
			return ;
		}
	}
	std::cout << _name << ": my inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_SLOT)
	{
		std::cout << _name << ": AMateria index is out of range!" << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_SLOT || i < idx; ++i)
	{
		if (i == idx)
		{
			if (_inv[i])
			{
				_inv[i] = 0;
				std::cout << _name << ": I unequipped the AMateria" << std::endl;
			}
			else
				std::cout << _name << ": AMateria does not exist at this index!" << std::endl;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_SLOT)
	{
		std::cout << _name << ": AMateria index is out of range!" << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_SLOT || i < idx; ++i)
	{
		if (i == idx)
		{
			if (_inv[i])
				_inv[i]->use(target);
			else
				std::cout << _name << ": AMateria does not exist at this index!" << std::endl;
		}
	}
}


// Constructors + Destructor

Character::Character()
	: _name{"nameless"}
	, _invSize{0}
	, _inv{0}
{
	std::cout << "Character: Default constructor called" << std::endl;
}

Character::Character(const Character& obj)
{
	std::cout << "Character: Copy constructor called" << std::endl;
	*this = obj;
}

Character& Character::operator=(const Character& obj)
{
	std::cout << "Character: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

Character::~Character()
{
	std::cout << "Character: Destructor called" << std::endl;
}
