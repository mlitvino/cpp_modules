#include "ICharacter.hpp"

// Constructors + Destructor

ICharacter::ICharacter()
{
	std::cout << "ICharacter: Default constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter& obj)
{
	std::cout << "ICharacter: Copy constructor called" << std::endl;
	*this = obj;
}

ICharacter& ICharacter::operator=(const ICharacter& obj)
{
	std::cout << "ICharacter: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}
