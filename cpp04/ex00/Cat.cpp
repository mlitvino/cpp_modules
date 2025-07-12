#include "Cat.hpp"

void	Cat::makeSound() const
{
	std::cout << "Cat: makeSound: meEEEEoooOOooow!" << std::endl;
}

// Constructors + Destructor

Cat::Cat()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}

Cat::Cat(const Cat& obj)
	: Animal()
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	*this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
	std::cout << "Cat: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	type = obj.type;
	return *this;
}
