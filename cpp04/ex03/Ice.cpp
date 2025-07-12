#include "Ice.hpp"

Ice* Ice::clone() const
{
	return new Ice;
}

void Ice::use(ICharacter& target)
{
	std::cout
	<< "* shoots an ice bolt at " << target.getName() << " *"
	<< std::endl;
}

// Constructors + Destructor

Ice::Ice()
	: AMateria("ice")
{
	std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::Ice(const Ice& obj)
	: AMateria("ice")
{
	std::cout << "Ice: Copy constructor called" << std::endl;
	*this = obj;
}

Ice& Ice::operator=(const Ice& obj)
{
	std::cout << "Ice: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice: Destructor called" << std::endl;
}
