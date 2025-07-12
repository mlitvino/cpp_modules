#include "Cure.hpp"

Cure* Cure::clone() const
{
	return new Cure;
}

void Cure::use(ICharacter& target)
{
	std::cout
	<< "* heals " << target.getName() << "'s wounds *"
	<< std::endl;
}

// Constructors + Destructor

Cure::Cure()
	: AMateria("cure")
{
	std::cout << "Cure: Default constructor called" << std::endl;
}

Cure::Cure(const Cure& obj)
	: AMateria("cure")
{
	std::cout << "Cure: Copy constructor called" << std::endl;
	*this = obj;
}

Cure& Cure::operator=(const Cure& obj)
{
	std::cout << "Cure: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure: Destructor called" << std::endl;
}
