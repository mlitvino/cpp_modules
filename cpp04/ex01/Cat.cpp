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
	brain =  new Brain;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
	delete brain;
}

Cat::Cat(const Cat& obj)
	: Animal()
	, brain(new Brain(*obj.brain))
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	type = obj.type;
}

Cat& Cat::operator=(const Cat& obj)
{
	std::cout << "Cat: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	type = obj.type;
	delete brain;
	brain = new Brain(*obj.brain);
	return *this;
}
