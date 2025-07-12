#include "Animal.hpp"

const std::string&	Animal::getType() const
{
	return type;
}

void	Animal::makeSound() const
{
	std::cout << "Amimal: makeSound: animal noises" << std::endl;
}

// Constructors + Destructor

Animal::Animal()
	: type{"Animal"}
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
}

Animal::Animal(const Animal& obj)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
	*this = obj;
}

Animal& Animal::operator=(const Animal& obj)
{
	std::cout << "Animal: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	type = obj.type;
	return *this;
}

