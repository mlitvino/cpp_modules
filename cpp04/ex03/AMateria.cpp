#include "AMateria.hpp"

void AMateria::use(ICharacter& target)
{
	std::cout
	<< "* unknown hokus pokus at " << target.getName() << " *"
	<< std::endl;
}

std::string const& AMateria::getType() const
{
	return _type;
}

// Constructors + Destructor

AMateria::AMateria()
{
	std::cout << "AMateria: Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria: Arg constructor called" << std::endl;
	_type = type;
}

AMateria::AMateria(const AMateria& obj)
{
	std::cout << "AMateria: Copy constructor called" << std::endl;
	*this = obj;
}

AMateria& AMateria::operator=(const AMateria& obj)
{
	std::cout << "AMateria: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria: Destructor called" << std::endl;
}
