#include "WrongAnimal.hpp"

const std::string&	WrongAnimal::getType() const
{
	return type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal: makeSound: WrongAnimal noises" << std::endl;
}

// Constructors + Destructor

WrongAnimal::WrongAnimal()
	: type{"WrongAnimal"}
{
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
	: type{obj.type}
{
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	std::cout << "WrongAnimal: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	type = obj.type;
	return *this;
}

