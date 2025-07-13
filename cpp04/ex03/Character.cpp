#include "Character.hpp"

std::string const& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		if (!_inv[i])
		{
			_inv[i] = m;
			std::cout << _name << ": I equipped the " << m->getType() << std::endl;
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
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		if (i == idx)
		{
			if (_inv[i])
			{
				std::cout << _name << ": I unequipped the " << _inv[i]->getType() << std::endl;
				_inv[i] = nullptr;
			}
			else
				std::cout << _name << ": AMateria does not exist at this index!" << std::endl;
			return ;
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
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		if (i == idx)
		{
			if (_inv[i])
				_inv[i]->use(target);
			else
				std::cout << _name << ": AMateria does not exist at this index!" << std::endl;
			return ;
		}
	}
}

// Constructors + Destructor

Character::Character()
	: _name{"nameless"}
	, _inv{nullptr}
{
	std::cout << "Character: Default constructor called" << std::endl;
}

Character::Character(const std::string& name)
	: _name{name}
	, _inv{nullptr}
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
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		delete _inv[i];
		if (obj._inv[i])
			_inv[i] = obj._inv[i]->clone();
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character: Destructor called" << std::endl;
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		if (_inv[i])
			delete _inv[i];
	}
}
