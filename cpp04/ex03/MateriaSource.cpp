#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria* obj)
{
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		if (!_inv[i])
		{
			_inv[i] = obj;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		if (_inv[i] && _inv[i]->getType() == type)
			return _inv[i]->clone();
	}
	std::cout << "MateriaSource: Materia not found" << std::endl;
	return nullptr;
}

// Constructors + Destructor

MateriaSource::MateriaSource()
	: _inv{nullptr}
{
	std::cout << "MateriaSource: Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
	: MateriaSource()
{
	std::cout << "MateriaSource: Copy constructor called" << std::endl;
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	std::cout << "MateriaSource: Copy assignment constructor called" << std::endl;
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

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: Destructor called" << std::endl;
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		if (_inv[i])
			delete _inv[i];
	}
}
